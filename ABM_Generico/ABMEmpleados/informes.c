/*
 * informes.c
 *
 *  Created on: 3 may. 2021
 *      Author: laura
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "informes.h"


int informesEmpleados(eEmpleado lista[], int tam, eSector sectores[], int tamS){
	eEmpleado aux;
	int opcion;
	int retorno = -1;
	if(lista != NULL && tam > 0){
		printf("\n\t 1) Nombre ascendente \n\t 2) Edad Ascendente \n\t 3) Empleado por sector \n\t 4) Aumentar sueldo \n\t 5) A ponerla \n\t 8) Volver \n\t Ingrese opcion informe: ");
		scanf("%d", &opcion);
		switch(opcion){
			case 1://Nombre ascend
				for(int i = 0; i < tam -1; i++){
					for(int j = i+1; j < tam; j++){
						if(strcmp(lista[i].nombre, lista[j].nombre) > 0){ //mayor a cero: el segundo str mas grande - menor a cero: el primero mas grande
							aux = lista[i];
							lista[i] = lista[j];
							lista[j] = aux;
						}
					}
				}
				mostrarEmpleados(lista, tam,sectores,tamS);
				break;
			case 2://Edad ascendente
				for(int i = 0; i < tam -1; i++){
					for(int j = i+1; j < tam; j++){
						if(lista[i].edad > lista[j].edad){
							aux = lista[i];
							lista[i] = lista[j];
							lista[j] = aux;
						}
					}
				}
				mostrarEmpleados(lista, tam,sectores,tamS);
				break;
			case 3:
				empleadosSector(lista, tam, sectores, tamS);
				break;
			case 4:
				actualizarSueldoSector(lista, tam, sectores, tamS);
				break;
			case 5:
				aPonerla(lista, tam, sectores, tamS);
				break;
			case 8:
				break;
		}

		retorno = 1;
	}

	return retorno;
}

//REFACTOR: hacer recorriendo sector y depsues lista, posible array de resultados
int aPonerla(eEmpleado lista[], int tam, eSector sectores[], int tamS){
	/*float totalSistemas = 0;
	float totalRRHH = 0;
	float totalCobranzas = 0;
	float totalLegales = 0;
	float totalVentas = 0;
	for(int i = 0; i < tam; i++){
		switch(lista[i].idSector){
			case 500:
				totalSistemas += lista[i].sueldo;
				break;
			case 501:
				totalRRHH += lista[i].sueldo;
				break;
			case 502:
				totalCobranzas+= lista[i].sueldo;
				break;
			case 503:
				totalLegales += lista[i].sueldo;
				break;
			case 504:
				totalVentas += lista[i].sueldo;
				break;
		}
	}
	float totalPoner = totalSistemas + totalRRHH + totalCobranzas + totalLegales + totalVentas;
	printf("Total por sector: \n Sistemas: %f \n RRHH: %f \n Cobranzas: %f \n Legales: %f \n Ventas: %f \n",totalSistemas, totalRRHH, totalCobranzas, totalLegales, totalVentas);
	printf("Total a 'poner': %f", totalPoner);
	return 1;*/

	float totalSector ;
	float total = 0;
	int retorno = -1;
	if(lista != NULL && tam > 0 && sectores != NULL && tamS > 0){
		printf("\n\n--- Sueldos por sector---\n");
		for(int i = 0; i < tamS; i++){

			printf("Sector: %s\n", sectores[i].descripcion);
			totalSector = 0;

			for(int j = 0; j < tam; j++){

				if(lista[j].isEmpty == 0 && lista[j].idSector == sectores[i].id){
					totalSector += lista[j].sueldo;
				}
			}
			printf(" -- Total: $%.2f \n",totalSector);
			total += totalSector;
		}
		printf("\n ---- Total sueldos empresa: %.2f\n\n ",total);
		retorno = 1;
	}
	return retorno;
}

int empleadosSector(eEmpleado lista[], int tam, eSector sectores[], int tamS){
	int sector;
	int cant = 0;
	char descripcion[20];
	if(lista != NULL && tam > 0 && sectores != NULL && tamS > 0){
		mostrarSectores(sectores,tamS);
		printf("Ingrese sector a informar: ");
		scanf("%d", &sector);
		cargarDescripcionSector(sector,sectores,tam, descripcion);
		for(int i = 0; i < tam; i++){
			if(lista[i].idSector == sector && lista[i].isEmpty == 0){
				cant++;
			}
		}

	}
	if(cant > 0){
		printf("\n--- Para el sector %s hay %d empleados --\n", descripcion, cant);
	}else{
		printf("\n--- No hay empleados de sector %s --\n", descripcion);
	}
	return cant;
}

int actualizarSueldoSector(eEmpleado lista[], int tam, eSector sectores[], int tamS){
	int retorno = -1;
	int sector;
	int porcentaje;
	if(lista != NULL && tam > 0 && sectores != NULL && tam > 0){
		printf("\n\n----- Actualizar sueldo ------\n");
		mostrarSectores(sectores,tamS);
		printf("  Ingrese ID sector: ");
		scanf("%d",&sector);
		printf("\n   Ingrese porcentaje a aumentar: ");
		scanf("%d",&porcentaje);
		for(int i = 0; i < tam; i++){
			if(lista[i].isEmpty == 0 && lista[i].idSector == sector){
				lista[i].sueldo = lista[i].sueldo + lista[i].sueldo * porcentaje/100;
			}
		}
		retorno = 1;
	}
	return retorno;
}
