#include <stdio.h>
#include <stdlib.h>
#include "comida.h"
#include <string.h>
#include <ctype.h>

int mostrarComidas(eComida comidas[], int tam){
	if(comidas != NULL && tam > 0){
		printf("\n\t   --- Lista de Comidas ---\n");
		printf("\t ID   Descripcion  Precio\n");
		for(int i = 0; i < tam; i++){
			mostrarComida(comidas[i]);
		}
		printf("\n\n");
	}
	return 1;
}

int mostrarComida(eComida unComida){
	printf("\t %d  %10s  %.2f \n",unComida.id, unComida.descripcion, unComida.precio);
	return 1;
}

int buscarComida(int idComida, eComida comidas[], int tam){
	int retorno = -1;
	if(idComida >= 0 && comidas != NULL && tam > 0){
		for(int i = 0; i < tam; i++){
			if(idComida == comidas[i].id ){
				printf("--Comida existente--\n");
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}

int cargarDescripcionComida(int id , eComida comidas[], int tam, char descripcion[]){
	int retorno = -1;
	if(id >= 1000 && id <= 1004 && comidas != NULL && tam > 0 && descripcion != NULL){
		for(int i = 0; i < tam; i++){
			if(comidas[i].id == id){
				strcpy(descripcion, comidas[i].descripcion);
				retorno = 1;
				break;
			}
		}
	}
	return retorno;
}
