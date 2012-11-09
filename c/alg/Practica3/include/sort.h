#ifndef _SORT_H
#define _SORT_H

#include <stdio.h>

/*
 * Ordenación por Insercción.
 * 
 * Un vector de datos v, de tamaño n, donde cada elemento ocupa size bytes, 
 * empleando la función cmp para comparar cada elemento. x será un elemento
 * del mismo tipo que actuará de elemento temporal. 
 * En cada iteración se realizará una llamada a cmp con la dirección donde 
 * se encuentran los dos elementos a comparar. El valor esperado es menor,
 * igual o mayor que 0 si el primer elemento es menor, igual o mayor que el
 * segundo respectivamente.
 */
void insertsort
(
	register void *v, 
	register unsigned long n, 
	register size_t size, 
	register int (*cmp)(void *, void *)
);


/*
 * Ordenación por Insercción para enteros.
 * 
 * Un caso optimizado de la función anterior para ordenar un vector de enteros
 * v, cuya longitud es n. La ordenación es de menor a mayor.
 * 
 */
void insertsort_int
(
	register int *v, 
	register unsigned long n
);


/*
 * Ordenación por QuickSort.
 * 
 * Ordena un vector de elementos v, de tamaño size, y con n elementos. Para la
 * ordenación se usa la función insertsort a partir de un umbral especificado.
 * Los elementos se ordenan llamando a la funcion cmp, a la cual se le indica
 * la posición de los dos elementos a comparar. Si el primer elemnto comparado
 * con el segundo es, menor, igual o mayor que 0, debe devolver un entero menor
 * igual o mayor que 0.
 * 
 * Si se desea, se pueden ordenar enteros más eficientemente, empleando la fun-
 * ción quicksort_int automáticamente. Para ello especificar la función cmp a
 * NULL.
 * 
 */
void quicksort
(	
	register void *v, 
	register int umbral, 
	register unsigned long n, 
	register size_t size, 
	register int (*cmp)(void *, void *)
);


/*
 * Ordenación por QuickSort para enteros.
 *
 * Ordena un vector de enteros (int) v, con n elementos. Emplea el umbral espe-
 * cificado. La ordenación también es de menor a mayor.
 */
void quicksort_int
(
	register int *v, 
	register unsigned long n, 
	register int umbral
);


#endif
