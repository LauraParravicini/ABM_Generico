/*
 ============================================================================
 Name        : Empleados.c
 Author      :
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "fecha.h"
//#include "empleado.h"
#include "comida.h"
#include "almuerzo.h"
#include "informes.h"
//#include "datawarehouse.h"
//TAREA: MENU 1) alta , hay lugar en el vector? devuelve indice de la primera estructura libre (buscar libre, isEmpty = 1)
//                                               si no hay, devuelvo -1 e informo,
//                                               si hay, pedir legajo (v2: generar legajo) chequear (buscar empleado) ->  si ya existe legajo, informar y devolver el indice
//                        																          -> si no existe legajo (devuelve -1) y pido el resto de los datos y los pongo en el indice de buscar libre
// 2) modif emp 3) baja (isEMpty) 4) listar emps 5) salir

//se recomienda pasar a int para hacer validacion de funcion

//--------TAREA: AGREGAR VALIDACION != NULL DE PUNTERO EN FUNCION
//              MODIFICACION: SUB MENU (LISTO)
//				OPCION PARA ORDENAR (LISTO) Y MOSTRAR SECTORES (LISTO)
//			   	INFORMES (ORDENAMIENTOS, otra opcion) (LISTO)
//				FUNCION PARA CARGAR DUMMY (OPCIONAL)
//HACER LINK DE ID - DESCRIPCION DE SECTOR

void sectorQueMasCobra(eEmpleado lista[],int tam, eSector sectores[], int tamS);
int empleadoActivo(eEmpleado empleado);
int empleadoInactivo(eEmpleado empleado);
int perteneceSector(eEmpleado empleado, int idSector);

int main(void) {
	eEmpleado nomina[TAM];
    eAlmuerzo almuerzos[TAMA];

	inicializarEmpleados(nomina,TAM);
    inicializarAlmuerzos(almuerzos, TAMA);

	eSector sectores[TAMSEC] = {
			{500,"Sistemas"},{501,"RRHH"},{502,"Cobranzas"},{503,"Legales"},{504,"Ventas"}
	};
	eComida comidas[TAMC] = {
			{1000,"Milanesa",100},{1001,"Fideos",200},{1002,"Churrasco",200},{1003,"Ensalada",300},{1004,"Pescado",400}
	};

	int opcion;
	int status;
    int nextId = 20000;
    int nextIdAlmuerzo = 50000;

    hardcodearEmpleados(nomina, TAM, 5, &nextId);
    //hardcodearAlmuerzos(almuerzos,TAMA,20,&nextIdAlmuerzo);
    //--- Menu ----
    do{
        printf("\n---------- Bienvenido -------\n");
        printf("1) Alta \n2) Modificacion \n3) Baja \n4) Listar \n5) Ordenar \n6) Mostrar Sectores \n7) Informes \n8) Mostrar comidas \n9) Alta almuerzo \n10) Mostrar almuerzos \n11)Sector Carero \n20) Salir\n");
        printf("Ingrese opcion 1-20: ");
        scanf("%d", &opcion);

        switch(opcion){
            case ALTA:
                status = altaEmpleado(nomina,TAM,&nextId);
                status == -1 ? printf("-- Hubo problema al dar el alta --\n") : printf("-- Se añadio --\n");
                break;
            case MODIF:
                status = modifEmpleado(nomina,TAM,sectores,TAMSEC);
                status == -1 ? printf("-- Error al editar --\n") : printf("-- Editado con exito --\n");
                break;
            case BAJA:
                status = bajaEmpleado(nomina, TAM,sectores,TAMSEC);
                status == -1 ? printf("-- Hubo error/se cancelo --\n") : printf("-- Se borro --\n");
                break;
            case LISTAR:
                mostrarEmpleados(nomina,TAM,sectores,TAMSEC);
                break;
            case ORDENAR:
                status = ordenarEmpleados(nomina,TAM);
                status == -1 ? printf("-- Hubo error al ordenar --\n") : printf("-- Ordenado exitoso --\n");
                break;
            case MOSTRAR_SEC:
                mostrarSectores(sectores, TAMSEC);
                break;
            case INFORMES:
                status = informesEmpleados(nomina, TAM, sectores, TAMSEC);
                status == -1 ? printf("-- Error al generar informe --\n") : printf("-- Generado --\n");
                break;
            case COMIDAS:
                status = mostrarComidas(comidas,TAMC);
                status == -1 ? printf("-- Error al mostrar --\n") : printf("-------\n");
                break;
            case ALTALMUERZO:
                status = altaAlmuerzo(almuerzos,TAMA,nomina,TAM,sectores,TAMSEC,comidas,TAMC,&nextIdAlmuerzo);
                status == -1 ? printf("-- Error al cargar almuerzo --\n") : printf("\n---- Almuerzo Cargado---\n");
                break;
            case ALMUERZOS:
                status = mostrarAlmuerzos(almuerzos,TAMA,comidas,TAMC,nomina,TAM);
                status == -1 ? printf("-- Error al mostrar --\n") : printf("-------\n");
                break;
            case 11:
               sectorQueMasCobra(nomina,TAM,sectores,TAMSEC);
                break;
        }
    }while(opcion != SALIR);

	return EXIT_SUCCESS;
}

void sectorQueMasCobra(eEmpleado lista[],int tam, eSector sectores[], int tamS){
    float totalSector ;
	int maxSector = 0;
	float totales[tamS];
    //Igualdad de indice entre el vector de sueldos y sectores, cuando encuentro el mayor en sector, su descrip esta en la misma posic de sectores
	if(lista != NULL && tam > 0 && sectores != NULL && tamS > 0){

        for(int i = 0; i < tamS; i++){

            totalSector = 0;
			for(int j = 0; j < tam; j++){

				if( empleadoActivo(lista[j]) && perteneceSector(lista[j],sectores[i].id) ){
					totalSector += lista[j].sueldo;
				}
			}
			//Cargue los totales en el array
			totales[i] = totalSector;
		}

        //Busco el valor maximo en el array
        maxSector = totales[0];
		for(int i = 1; i < tamS; i++){
            if(totales[i] > maxSector){
                maxSector = totales[i];
            }
        }

        //Vuelvo a recorrer el array buscando si el maximo se repite, si se repite muestro la descripcion de sectores
        printf("Sectores que mas cobran: ");
        for(int i = 0; i < tamS; i++){
            if(totales[i] == maxSector){
                printf(" %s",sectores[i].descripcion);
            }
        }
        printf("\n\n");

	}
}

int empleadoActivo(eEmpleado empleado){
    return !empleado.isEmpty;
}
int empleadoInactivo(eEmpleado empleado){
    return empleado.isEmpty;
}

int perteneceSector(eEmpleado empleado, int idSector){
    return empleado.idSector == idSector;
}
