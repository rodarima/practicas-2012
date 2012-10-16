#include <stdio.h>


int medir_tiempo_fvector(int (*f)(int [], int), int v[], int n){
	return f(v, n);
}

