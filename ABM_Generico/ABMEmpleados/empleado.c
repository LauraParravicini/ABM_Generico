#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "datawarehouse.h"
#include "Empleado.h"


void mostrarEmpleado(eEmpleado emp, eSector sectores[], int tam){
	if(sectores != NULL && tam > 0){
		char descripcion[20];
		if(cargarDescripcionSector(emp.idSector, sectores, tam, descripcion)){

            printf("%d    %10s          %d       %c    %.2f    %02d/%02d/%02d    %s\n",
			emp.legajo,
			emp.nombre,
			emp.edad,
			emp.sexo,
			emp.sueldo,
			emp.ingreso.dia,
			emp.ingreso.mes,
			emp.ingreso.anio,
			descripcion);
		}else{
            printf("-!- No tiene sector valido -!-");
		}
	}
}


void mostrarEmpleados(eEmpleado lista[], int tam, eSector sectores[], int tamS){
	int flagVacio = 1;
	if(lista != NULL && tam > 0 && sectores != NULL && tamS > 0){
		printf("\n\t ---- Lista Empleados ---- \n");
		printf("Legajo       Nombre        Edad    Sexo    Sueldo    Fecha Ingreso    Sector\n");
		for(int i = 0; i < tam; i++){
			if(!lista[i].isEmpty){
				mostrarEmpleado(lista[i],sectores,tamS);
				flagVacio = 0;
			}
		}
		if(flagVacio){
			printf("No hay empleados en la lista");
		}
		printf("\n\n");
	}
}


//--- TAREA: Opciones: por parametro, o por menu
int ordenarEmpleados(eEmpleado lista[], int tam){
	eEmpleado aux;
	int retorno = -1;
	// por edad descendente
	/*for(int i = 0; i < tam -1; i++){
		for(int j = i+1; j < tam; j++){
			if(lista[i].edad < lista[j].edad){
				aux = lista[i];
				lista[i] = lista[j];
				lista[j] = aux;
			}
		}
	}*/
	//Por sexo desc y legajo ascendente
	if(lista != NULL && tam > 0){
		for(int i = 0; i < tam -1; i++){
				for(int j = i+1; j < tam; j++){
					if( lista[i].sexo < lista[j].sexo ||
						(lista[i].sexo == lista[j].sexo &&  lista[i].legajo > lista[j].legajo) ){ //mayor a cero: el segundo str mas grande - menor a cero: el primero mas grande
						aux = lista[i];
						lista[i] = lista[j];
						lista[j] = aux;
					}
				}
			}
		retorno = 1;
	}
	return retorno;
}

void inicializarEmpleados(eEmpleado lista[], int tam){
	if(lista != NULL && tam > 0){
		for(int i = 0; i < tam; i++){
			lista[i].isEmpty = 1;
		}
	}
}

int buscarEmpleado(int legajoIngresado, eEmpleado lista[], int tam){
	int retorno = -1;
	if(legajoIngresado >= 0 && lista != NULL && tam > 0){
		for(int i = 0; i < tam; i++){
			if(legajoIngresado == lista[i].legajo && !lista[i].isEmpty ){
				printf("---Legajo existente---\n");
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}

int bajaEmpleado(eEmpleado lista[], int tam, eSector sectores[], int tamS){
	int retorno = -1;
	int legajoBorrar;
	char confirmacion;
	if(lista != NULL && tam > 0 && sectores != NULL && tamS > 0){
		printf("\n--- Lista Empleados - Baja --- \n");
		mostrarEmpleados(lista,tam,sectores,tamS);

		printf("Ingrese legajo a borrar: ");
		scanf("%d", &legajoBorrar);
		int indiceBorrar = buscarEmpleado(legajoBorrar,lista,tam);
		if(indiceBorrar >= 0){
			mostrarEmpleado(lista[indiceBorrar],sectores,tamS);
			printf("\n¿Quiere borrarlo? s/n: ");
            fflush(stdin);
			scanf(" %c",&confirmacion);
			if(confirmacion == 's'){
				lista[indiceBorrar].isEmpty = 1;
				retorno = 1;
			}else{
				printf("-- No se borro --\n");
				retorno = -1;
			}
		}else{
			printf("--No existe--");
			retorno = -1;
		}
	}
	return retorno;
}

//-----TAREA: Hacer un menu q pregunte que quiere modificar, confirmacion y sobrescribir. similar BAJA
int modifEmpleado(eEmpleado lista[], int tam, eSector sectores[], int tamS){
	int legajoIngresado;
	int indiceExiste = 0;
	int opcion;
	int retorno = -1;
	if(lista != NULL && tam > 0){
		printf("\nIngrese legajo de empleado a modificar: ");
		scanf("%d", &legajoIngresado);
		indiceExiste = buscarEmpleado(legajoIngresado,lista,tam);
		if(indiceExiste >= 0){
			printf("--Editando--\n");
			mostrarEmpleado(lista[indiceExiste],sectores,tamS);
			printf("\t 1) Nombre \t\n 2) Edad \t\n 3) Sexo \t\n 4) Sueldo \t\n 5) Fecha Inicio \t\n 6) Volver \n Ingrese opcion 1-7: ");
			printf("\nIngrese opcion 1-7: ");
			scanf("%d", &opcion);
				switch(opcion){
					case 1:
						printf("Ingrese nombre: ");
						fflush(stdin);
						gets(lista[indiceExiste].nombre);
						break;
					case 2:
						printf("Ingrese edad: ");
						scanf("%d", &lista[indiceExiste].edad);
						break;
					case 3:
						printf("Ingrese sexo: ");
						scanf(" %c", &lista[indiceExiste].sexo);
						break;
					case 4:
						printf("Ingrese sueldo: ");
						scanf("%f", &lista[indiceExiste].sueldo);
						break;
					case 5:
						printf("Ingrese fecha de inicio: ");
						scanf("%d/%d/%d", &lista[indiceExiste].ingreso.dia, &lista[indiceExiste].ingreso.mes, &lista[indiceExiste].ingreso.anio);
						break;
					case 6:
						break;
				}
				retorno = 1;
		}else{
			printf("--- No existe el user ---\n");
			retorno = -1;
		}
	}
	return retorno;
}

//----Agrego break para que no sobrescriba con la ultima estructura
int buscarLibre(eEmpleado lista[], int tam){
	int indiceLibre = -1;
	if(lista != NULL && tam > 0){
		for(int i = 0; i < tam; i++){
			if(lista[i].isEmpty){
				indiceLibre = i;
				break;
			}
		}
	}
	return indiceLibre;
}

//--Las funcionalidades van despues de la validacion de parametros
//--Pasa por puntero el id y despues lo incrementa
int altaEmpleado(eEmpleado lista[], int tam, int* pId){
	int retorno = -1;
	eEmpleado nuevo;
	if(lista != NULL && tam > 0 && pId != NULL){
		int lugar = buscarLibre(lista, tam);
		if(lugar >= 0){
			 	nuevo.legajo = *pId;
				printf("Ingrese nombre: ");
                fflush(stdin);
				gets(nuevo.nombre);
				retorno = utn_getNumero(&nuevo.edad,"Ingrese edad: ","\n-!- Invalido.-!-\n",18,150,10);
				retorno = utn_getCaracter(&nuevo.sexo,"Ingrese sexo: ","\n-!- Invalido. -!-\n",'f','m',10);
				printf("Ingrese sueldo: ");
				scanf("%f", &nuevo.sueldo);
				retorno = utn_getFecha(&nuevo.ingreso.dia,&nuevo.ingreso.mes,&nuevo.ingreso.anio,"Ingrese fecha de ingreso: ","\n-!- Invalido. -!-\n",10);
				printf("Ingrese sector (500-504): ");
				scanf("%d", &nuevo.idSector);
				nuevo.isEmpty = 0;
				//Actualizo el id
                if(retorno){
                    lista[lugar] = nuevo;
                }else{
                    printf("\n--Error al asignar--\n");
                }
				(*pId)++;
				retorno = 1;
		}else{
			printf("- No hay lugar -");
			retorno = -1;
		}
	}
	return retorno;
}

int hardcodearEmpleados(eEmpleado lista[], int tam, int cant, int* pLegajo){
	int total = 0;
	if(lista != NULL && tam > 0 && cant >= 0 && cant < tam && pLegajo != NULL){
		for(int i = 0; i < cant; i++){
			lista[i].legajo = *pLegajo;
			(*pLegajo)++;
			strcpy(lista[i].nombre ,nombres[i]);
			lista[i].sexo = sexos[i];
			lista[i].sueldo = sueldos[i];
			lista[i].edad = edades[i];
			lista[i].idSector = idSectores[i];
			lista[i].isEmpty = 0;
			lista[i].ingreso = fechas[i];
			total++;
		}
	}
	return total;
}

int cargarNombreEmpleado(int legEmpleado,eEmpleado lista[],int tamE,char nombre[]){
    int retorno = -1;
	if(lista != NULL && tamE > 0 && nombre != NULL){
		for(int i = 0; i < tamE; i++){
			if(legEmpleado == lista[i].legajo && !lista[i].isEmpty){
				strcpy(nombre, lista[i].nombre);
				retorno = 1;
				break;
			}
		}
	}
	return retorno;
}
