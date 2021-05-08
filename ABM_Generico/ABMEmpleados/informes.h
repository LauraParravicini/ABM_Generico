#include "empleado.h"

#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED



int informesEmpleados(eEmpleado lista[], int tam, eSector sectores[], int tamS);
int aPonerla(eEmpleado lista[], int tam, eSector sectores[], int tamS);
int empleadosSector(eEmpleado lista[], int tam, eSector sectores[], int tamS);
int actualizarSueldoSector(eEmpleado lista[], int tam, eSector sectores[], int tamS);

#endif // INFORMES_H_INCLUDED
