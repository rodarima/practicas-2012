#include "tabla.h"
/*
int vector[] = {-9, 2, -5, -4, 6};
struct tabla_t funcion_f1 = {sumaSubMax1, vector, 5, MAX_K};
struct tabla_t tabla_t1 = {"hola", 2, 32, 2,  &funcion_f1, sub, norm, sob};
*/
void imprimir_linea_tabla(struct funcion_t *funcion, int i)
{
	int entro;
	double t = medir_tiempo_fvector(funcion, &entro)
	double h = cota_n(i, t);
	double g = cota_n(i, t);
	double f = cota_n(i, t);
	printf("%9d%15.3f%15.6f%15.6f%15.6f\n", i, t, h, g, f);
	/*
	 * Si entro ... mostrar k
	 * 
	 */
}

void imprimir_tabla(struct tabla_t *tabla)
{
	printf("Tabla de: %s\n", tabla->titulo);
	int i;
	for(i=tabla->min; i<=tabla->max; i*=tabla->paso){
		imprimir_linea_tabla(tabla->funcion, i);
	}
}


