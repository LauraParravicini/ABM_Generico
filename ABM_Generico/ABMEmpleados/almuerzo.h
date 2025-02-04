
#include "comida.h"
#include "fecha.h"
#include "empleado.h"
#ifndef ALMUERZO_H_INCLUDED
#define ALMUERZO_H_INCLUDED

//#include "datawarehouse.h"
typedef struct{
	int id;
	int legEmpleado;
	int idComida;
	eFecha fecha;
	int isEmpty;
}eAlmuerzo;

//int hardcodearAlmuerzos(eAlmuerzo almuerzos[], int tam, int cant, int* pId);
int inicializarAlmuerzos(eAlmuerzo almuerzos[], int tam);
int buscarLibreAlmuerzo(eAlmuerzo almuerzos[], int tam);
int altaAlmuerzo(eAlmuerzo almuerzos[], int tamA , eEmpleado lista[], int tamE, eSector sectores[], int tamS, eComida comidas[], int tamC, int* pIdAlmuerzo);
int mostrarAlmuerzos(eAlmuerzo almuerzos[], int tam,eComida comidas[], int tamC,eEmpleado lista[], int tamE);
int mostrarAlmuerzo(eAlmuerzo unAlmuerzo,eComida comidas[], int tamC,eEmpleado lista[], int tamE);


#endif // ALMUERZO_H_INCLUDED
