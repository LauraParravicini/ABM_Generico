#ifndef BIBLIOLAU_H_INCLUDED
#define BIBLIOLAU_H_INCLUDED

int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);
int utn_getCaracter(char* pResultado, char* mensaje, char* mensajeError, char minimo, char maximo, int reintentos);
int utn_getFecha(int* dia,int* mes, int* anio, char* mensaje, char* msjeError,int reintentos);
int utn_getFloat(char * cadena);
#endif // BIBLIOLAU_H_INCLUDED
