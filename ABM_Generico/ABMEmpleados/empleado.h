
#include "fecha.h"
#include "bibliolau.h"
#ifndef EMPLEADO_H_INCLUDED
#define EMPLEADO_H_INCLUDED

#define ALTA 1
#define MODIF 2
#define BAJA 3
#define LISTAR 4
#define ORDENAR 5
#define MOSTRAR_SEC 6
#define INFORMES 7
#define COMIDAS 8
#define ALTALMUERZO 9
#define ALMUERZOS 10
#define SALIR 20

#define TAM 10
#define TAMSEC 5
#define TAMA 30
#define TAMC 5


typedef struct{
	int legajo;
	char nombre[20];
	int edad;
	char sexo;
	float sueldo;
	eFecha ingreso;
	int idSector;
	int isEmpty; //1 vacio, 0 ocupado

}eEmpleado;

#include "sectores.h"
#include "informes.h"
#include "almuerzo.h"
#include "comida.h"

void mostrarEmpleados(eEmpleado lista[], int tam, eSector sectores[], int tamS);
void mostrarEmpleado(eEmpleado emp, eSector sectores[], int tam);
int ordenarEmpleados(eEmpleado lista[], int tam);
int informesEmpleados(eEmpleado lista[], int tam, eSector sectores[], int tamS);
void inicializarEmpleados(eEmpleado lista[], int tam);

int buscarLibre(eEmpleado lista[], int tam);
int buscarEmpleado(int legajoIngresado, eEmpleado lista[], int tam);

int bajaEmpleado(eEmpleado lista[], int tam, eSector sectores[], int tamS);
int altaEmpleado(eEmpleado lista[], int tam, int* pId);
int modifEmpleado(eEmpleado lista[], int tam, eSector sectores[], int tamS);
void menuModificar(eEmpleado emp);
//void menu(eEmpleado lista[],int tam,eSector sectores[], int tamS, eComida comidas[], int tamC);

int empleadosSector(eEmpleado lista[], int tam, eSector sectores[], int tamS);
int hardcodearEmpleados(eEmpleado lista[], int tam, int cant, int* pLegajo);
int cargarDescripcionSector(int id , eSector sectores[], int tam, char descripcion[]);
int actualizarSueldoSector(eEmpleado lista[], int tam, eSector sectores[], int tamS);
int cargarNombreEmpleado(int legEmpleado,eEmpleado lista[],int tamE,char nombre[]);
//Informe pago sueldo
int aPonerla(eEmpleado lista[], int tam, eSector sectores[], int tamS);

#endif // EMPLEADO_H_INCLUDED
