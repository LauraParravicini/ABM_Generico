#ifndef COMIDA_H_INCLUDED
#define COMIDA_H_INCLUDED

typedef struct{
	int id;
	char descripcion[20];
	float precio;
}eComida;

int mostrarComidas(eComida comidas[], int tam);

int mostrarComida(eComida unComida);

int buscarComida(int idComida, eComida comidas[], int tam);

int cargarDescripcionComida(int id , eComida comidas[], int tam, char descripcion[]);
#endif // COMIDA_H_INCLUDED
