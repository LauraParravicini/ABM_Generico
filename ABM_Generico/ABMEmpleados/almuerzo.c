#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "almuerzo.h"

int inicializarAlmuerzos(eAlmuerzo almuerzos[], int tam){
	if(almuerzos != NULL && tam > 0){
		for(int i = 0; i < tam; i++){
			almuerzos[i].isEmpty = 1;
		}
	}
	return 1;
}

int buscarLibreAlmuerzo(eAlmuerzo almuerzos[], int tam){
	int indiceLibre = -1;
	if(almuerzos != NULL && tam > 0){
		for(int i = 0; i < tam; i++){
			if(almuerzos[i].isEmpty){
				indiceLibre = i;
				break;
			}
		}
	}
	return indiceLibre;
}

int altaAlmuerzo(eAlmuerzo almuerzos[], int tamA , eEmpleado lista[], int tamE, eSector sectores[], int tamS, eComida comidas[], int tamC, int* pIdAlmuerzo){
	int retorno = -1;
	int legajo;
	int idComida;
	eAlmuerzo nuevo;
	if(lista != NULL && tamE > 0 && pIdAlmuerzo != NULL && almuerzos != NULL && tamA > 0 && sectores != NULL && tamS > 0 && comidas != NULL && tamC > 0){
		int lugar = buscarLibreAlmuerzo(almuerzos, tamA);
		if(lugar >= 0){
			 	nuevo.id = *pIdAlmuerzo;
                //Cargar y validar legajo
			 	mostrarEmpleados(lista,tamE, sectores, tamS);
				utn_getNumero(&legajo,"Ingrese legajo de empleado: ","\n-!- Invalido.-!-\n",20000,50000,10);
                nuevo.legEmpleado = legajo;
                //Cargar y validar comida
				mostrarComidas(comidas, tamC);
                utn_getNumero(&idComida,"Ingrese ID de comida: ","\n-!- Invalido. -!-\n",1000,1005,10);
                nuevo.idComida = idComida;
                //Cargar y validar fecha
                utn_getFecha(&nuevo.fecha.dia,&nuevo.fecha.mes,&nuevo.fecha.anio,"Ingrese fecha almuerzo: ","\n-!- Fecha invalida -!-\n",10);
				nuevo.isEmpty = 0;
				almuerzos[lugar] = nuevo;
				(*pIdAlmuerzo)++;
				retorno = 1;
		}else{
			printf("- No hay lugar para mas almuerzos -");
			retorno = -1;
		}
	}
	return retorno;
}

int mostrarAlmuerzos(eAlmuerzo almuerzos[], int tam, eComida comidas[], int tamC,eEmpleado lista[], int tamE){
	int retorno = -1;
	int flagVacio = 1;
	if(almuerzos != NULL && tam > 0){
		printf("\t\n   --- Lista de Almuerzos ---\n");
		printf("\t   ID  Comida      Legajo Nombre    Fecha\n");
		for(int i = 0; i < tam; i++){
			if(!almuerzos[i].isEmpty){
				mostrarAlmuerzo(almuerzos[i],comidas, tamC,lista,tamE);
				flagVacio = 0;
			}
		}
		if(flagVacio){
			printf("No hay almuerzos en la lista");
		}
		printf("\n\n");
		retorno = 1;
	}
    return retorno;
}

int mostrarAlmuerzo(eAlmuerzo unAlmuerzo, eComida comidas[],int tamC, eEmpleado lista[], int tamE){
	char descrComida[20];
	char nombre[20];
    if(cargarDescripcionComida(unAlmuerzo.idComida, comidas, tamC, descrComida) &&
       cargarNombreEmpleado(unAlmuerzo.legEmpleado,lista,tamE,nombre)){
        printf("\t %5d %5s    %5d  %5s  %02d/%02d/%d \n",unAlmuerzo.id, descrComida,
                unAlmuerzo.legEmpleado,
                nombre,
                unAlmuerzo.fecha.dia, unAlmuerzo.fecha.mes, unAlmuerzo.fecha.anio);
    }else{
        printf("-!- Comida en almuerzo invalida -!-");
    }
	return 1;
}



