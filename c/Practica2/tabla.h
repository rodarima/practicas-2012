#ifndef TABLA_H
#define TABLA_H

struct funcion_t{
	int (*f)(int [], int);
	int v[];
	int n;
	int k;
};

struct tabla_t{
	char *titulo;
	
	int min;
	int max;
	int paso;
	
	struct funcion_t *funcion;
	
	double (*subestimada)	(int, double);
	double (*estimada)	(int, double);
	double (*sobrestimada)	(int, double);
};

#endif


