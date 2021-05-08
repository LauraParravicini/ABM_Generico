#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ---------- UTN Get Numero ---------
static int esNumerica(char* cadena);
static int getInt(int* pResultado);
static int myGets(char* cadena, int longitud);

static int myGets(char* cadena, int longitud){
	if(cadena != NULL && longitud > 0 && fgets(cadena,longitud,stdin) == cadena ){
		fflush(stdin);
		if(cadena[strlen(cadena)-1] == '\n'){
			cadena[strlen(cadena)-1] = '\0';
		}
		return 0;
	}
	return -1;
}

static int getInt(int* pResultado){
	int retorno = -1;
	char buffer[64];
	if(pResultado != NULL){
		if( myGets(buffer,sizeof(buffer)) == 0 && esNumerica(buffer) ){
			*pResultado = atoi(buffer);
			retorno = 0;
		}
	}
	return retorno;
}

static int esNumerica(char* cadena){
	int i = 0;
	int retorno = 1;
	if(cadena != NULL && strlen(cadena) > 0){
		while(cadena[i] != '\0'){
			if(cadena[i] < '0' || cadena[i] > '9'){
				retorno = 0;
				break;
			}
			i++;
		}
	}
	return retorno;
}

int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos){
	int bufferInt;
	int retorno = -1;
	while(reintentos > 0){
		reintentos--;
		printf("%s",mensaje);
		fflush(stdin);
		if(getInt(&bufferInt) == 0){
			if(bufferInt >= minimo && bufferInt <= maximo){
				*pResultado = bufferInt;
				retorno = 1;
				break;
			}
		}
        printf("%s",mensajeError);
	}
	return retorno;
}
//--------------------------   UTN Get Caracter -------------------------------------

int utn_getCaracter(char* pResultado, char* mensaje, char* mensajeError, char minimo, char maximo, int reintentos){
	int retorno = -1;
	char buffer;
	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos > 0){
		do{
			printf("%s",mensaje);
			scanf("%c",&buffer);
			if(buffer >= minimo && buffer <= maximo){
				*pResultado = buffer;
				retorno = 1;
				break;
			}
			printf("%s",mensajeError);
			reintentos--;

		}while(reintentos);
	}

	return retorno;
}
//----------------------------- UTN Get Fecha -----------------------
int utn_getFecha(int* dia,int* mes, int* anio, char* mensaje, char* msjeError,int reintentos){
    int retorno = -1;
    int bufDia, bufMes, bufAnio;
    if(dia != NULL && mes != NULL && anio != NULL && mensaje != NULL && msjeError != NULL && reintentos > 0){
        do{
            printf("%s", mensaje);
            scanf("%d/%d/%d", &bufDia, &bufMes, &bufAnio);
            if( bufDia >= 1 && ( ( (bufMes == 1 || bufMes == 3 || bufMes == 5 || bufMes == 7 || bufMes == 8 || bufMes == 10 || bufMes == 12) && bufDia <= 31)
                || ((bufMes == 4 || bufMes == 6 || bufMes == 9 || bufMes == 11) && bufDia <= 30)
                ||  (bufMes == 2 && bufDia <= 29) ) ){

                *dia = bufDia;
                *mes = bufMes;
                *anio = bufAnio;
                retorno = 1;
                break;
            }
            printf("%s",msjeError);
            reintentos--;
        }while(reintentos);
    }
    return retorno;
}

int utn_getFloat(char * cadena){
    int allRight = 1; //inicia en verdadero, y de no cumplir algun requisito la funcion le asignara el 0
    int contadorPunto = 0;
    int stop = 0;
    if (cadena != NULL && strlen(cadena) > 0){ //si el puntero cadena no apunta al vacio y su largo es mayor a 0
        for (int x = 0; x < strlen(cadena) && !stop ; x++){
            if (cadena[x] < '0' || cadena[x] > '9') //si el caracter no es numerico
            {
                switch(cadena[x]){
                    case '.':
                        if (contadorPunto > 1 || x == 0 || x == strlen(cadena)-1 || (x == 1 && cadena[0]== '-')) //si hay mas de un punto, o si este esta al final o al principio, o si prosigue a un signo negativo
                        {
                            allRight = 0;
                            stop = 1; //finaliza la iteracion (utilizar break entraria en conflicto con el switch)
                        }
                    break;
                    case '-':
                        if (x != 0 || strlen(cadena) == 1) //si el signo negativo no se encuentra al principio o si la cadena tiene solo 1 elemento
                        {
                            allRight = 0;
                            stop = 1;
                        }
                    break;
                    default:
                        allRight = 0;
                        stop = 1;
                }
            }
        }
    }
    return allRight;
}
