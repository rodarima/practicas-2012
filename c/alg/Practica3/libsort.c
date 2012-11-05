#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libsort.h"

#define swap_int(a, b, t) { (t) = (a); (a) = (b); (b) = (t); };


void insertsort_int(int *v, int n)
{
	register int *actual;
	register int *anterior = v;
	register int *last = v + n;
	register int t;

	for(actual = v+1; actual < last; actual++){
		anterior = actual-1;
		while((anterior >= v) && (*anterior > *(anterior+1)))
		{
			swap_int(*anterior, *(anterior+1), t);
			anterior--;
		}
	}
}

void swap(void *a, void *b, void *t, int n, size_t size)
{
	memcpy(t, a, n*size);
	memcpy(a, b, n*size);
	memcpy(b, t, n*size);
}

void swap1(register char *a,register char *b, register int bytes)
{
	register char t;
	while(bytes--){
		t=*a;
		*a=*b;
		*b=t;

		a++;
		b++;
	}
}


void med3(void *v, int n, int size, int (*cmp)(void *, void *))
{
	register void *min = v+(size*((n-1)>>1));
	register void *med = v;
	register void *max = v+(size*(n-1));
	
	if(cmp(min,med) == 1) swap4(min, med, size);
	if(cmp(med,max) == 1) swap4(med, max, size);
	if(cmp(min,med) == 1) swap4(min, med, size);
}

void insertsort(void *v, int n, size_t size, int (*cmp)(void *, void *))
{
	register void *actual;
	register void *anterior = v;
	register void *last = v + (n*size);

	for(actual = v+size; actual < last; actual+=size){
		anterior = actual-size;
		while((anterior >= v) && (cmp(anterior, anterior+size) == 1))
		{
			swap4(anterior, anterior+size, size);
			anterior-=size;
		}
	}
}


void med3_int(register int *v, register int n)
{
	register int *min = &v[((n-1)>>1)];
	register int *med = v;
	register int *max = &v[(n-1)];
	register int t;

	if(*min>*med){
		t = *min;
		*min=*med;
		*med=t;
	}
	if(*med>*max){
		t = *med;
		*med=*max;
		*max=t;
	}
	if(*min>*med){
		t = *min;
		*min=*med;
		*med=t;
	}
}
void _quicksort_int(register int *v, register int n, register int umbral)
{
	if(umbral>=n){
		return;
	}

	med3_int(v, n);

	register int *i = v;
	register int *j = v+(n-1);
	register int t, m;


	do
	{
		do { i++; } while((*i)<v[0]);
		do { j--; } while((*j)>v[0]);
		swap_int(*i, *j, t);
	}
	while(j>i);
	
	swap_int(*i, *j, t);
	swap_int(v[0], *j, t);

	m = (j-v);

	_quicksort_int(v, m, umbral);
	_quicksort_int(j+1, n-(m+1), umbral);
}

void quicksort_int(register int *v, register int n, register int umbral){
	_quicksort_int(v, n, umbral);
	if(umbral>=1) insertsort_int(v, n);
}


void _quicksort(register void *v, 
		register int umbral, 
		register int n, 
		register size_t size, 
		register int (*cmp)(void *, void *))
{


	register void *i = v;
	register void *j = v+((n-1)*size);
	register int m;

	if(umbral>=n) {
		return;
	}

	med3(v, n, size, cmp);

	do
	{
		do { i+=size; } while(cmp(i, v)==-1);
		do { j-=size; } while(cmp(j, v)== 1);
		swap4(i, j, size);
	}
	while(j>i);

	swap4(i, j, size);
	swap4(v, j, size);
	
	m = (j-v)/size;

	_quicksort(v, umbral, m, size, cmp);
	_quicksort(j+size, umbral, n-(m+1), size, cmp);
	
}
void quicksort(register void *v, 
		register int umbral, 
		register int n, 
		register size_t size, 
		register int (*cmp)(void *, void *))
{
	if(cmp == NULL){
		quicksort_int((int*)v, n, umbral);
		return;
	}
	_quicksort(v, umbral, n, size, cmp);
	if(umbral>=1) insertsort(v, n, size, cmp);
}

/*
void mergesort

void bubblesort
*/
