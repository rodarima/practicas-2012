#ifndef TABLA_H
#define TABLA_H
#include <stdio.h>
#include <stdlib.h>
#include "tiempo.h"


struct tabla_t{
	char *titulo;
	
	int min;
	int max;
	int paso;
	int k;
	
	int (*funcion)(int *, int);
	int (*crear)(int **, int);
	int (*rellenar)(int *, int);
	int (*borrar)(int *, int);
	
	double (*subestimada)	(int, double);
	double (*estimada)	(int, double);
	double (*sobrestimada)	(int, double);
};


void imprimir_tabla(struct tabla_t *tabla);

#endif


