#ifndef _LIBSORT_H
#define _LIBSORT_H

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
void insertsort(void *v, int n, size_t size, int (*cmp)(void *, void *));


/*
 * Ordenación por Insercción para enteros.
 * 
 * Un caso optimizado de la función anterior para ordenar un vector de enteros
 * v, cuya longitud es n. La ordenación es de menor a mayor.
 * 
 */
void insertsort_int(register int *v, register int n);

void med3(void *v, int n, int size, int (*cmp)(void *, void *));

void swap1(register char *a,register char *b, register int bytes);
void swap(void *a, void *b, void *t, int n, size_t size);
#define swap2(a, b, type) { type t = a; a = b; b = t; }

#define swap3(a, b) { 		\
	a ^= b;			\
	b ^= a;			\
	a ^= b;			\
}

#define swap4(a, b, size)						      \
  do									      \
    {									      \
      register size_t __size = (size);					      \
      register char *__a = (a), *__b = (b);				      \
      do								      \
	{								      \
		char __tmp = *__a;					      \
		*__a++ = *__b;						      \
		*__b++ = __tmp;						      \
	} while (--__size > 0);						      \
    } while (0)


void quicksort_int(register int *v, register int n, register int umbral);

void quicksort(	register void *v, 
		register int umbral, 
		register int n, 
		register size_t size, 
		register int (*cmp)(void *, void *));

#endif
