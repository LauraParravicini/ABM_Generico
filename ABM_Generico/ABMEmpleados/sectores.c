#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "sectores.h"
#ifndef SECTORES_C_INCLUDED
#define SECTORES_C_INCLUDED


void mostrarSectores(eSector sectores[], int tam){
	if(sectores != NULL && tam > 0){
		printf("\n   --- Lista de sectores ---\n");
		printf("\t ID   Descripcion\n");
		for(int i = 0; i < tam; i++){
			mostrarSector(sectores[i]);
		}
		printf("\n\n");
	}
}

void mostrarSector(eSector unSector){
	printf("\t %d  %10s\n ",unSector.id, unSector.descripcion);
}

int cargarDescripcionSector(int id , eSector sectores[], int tam, char descripcion[]){
	int retorno = -1;
	if(id >= 500 && id <= 504 && sectores != NULL && tam > 0 && descripcion != NULL){
		for(int i = 0; i < tam; i++){
			if(sectores[i].id == id){
				strcpy(descripcion, sectores[i].descripcion);
				retorno = 1;
				break;
			}
		}
	}
	return retorno;
}

#endif // SECTORES_C_INCLUDED
