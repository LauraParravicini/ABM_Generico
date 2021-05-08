

#ifndef SECTORES_H_INCLUDED
#define SECTORES_H_INCLUDED

typedef struct{
	int id;
	char descripcion[20];
}eSector;



#define TAMSEC 5



//BIblioteca Sector
void mostrarSectores(eSector sectores[], int tam);
void mostrarSector(eSector unSector);
int cargarDescripcionSector(int id , eSector sectores[], int tam, char descripcion[]);

#endif // SECTORES_H_INCLUDED
