#include "tabla.h"

void imprimir_linea_tabla(struct tabla_t *tabla, int *v, int n)
{
	int entro;
	double t = medir_tiempo_fvector(tabla->funcion, v, n, tabla->k, &entro);
	double h = tabla->subestimada(n, t);
	double g = tabla->estimada(n, t);
	double f = tabla->sobrestimada(n, t);
	printf("%9d%15.3f%15.6f%15.6f%15.6f", n, t, h, g, f);
	if(entro) printf("%9d\n", tabla->k);
	else printf("\n");
}

void imprimir_tabla(struct tabla_t *tabla)
{
	printf("\nTabla de: %s\n\n", tabla->titulo);
	int i;
	for(i=tabla->min; i<=tabla->max; i*=tabla->paso){
		int *v;
		if((tabla->crear) && (tabla->crear(&v, i)!=0)){
			perror("crear");
			exit(-1);
		}
		if(tabla->rellenar) tabla->rellenar(v, i);
		
		imprimir_linea_tabla(tabla, v, i);
		if(tabla->borrar) tabla->borrar(v, i);
	}
	printf("\n");
}


