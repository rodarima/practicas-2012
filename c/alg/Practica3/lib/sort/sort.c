#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sort.h"
#include "swap.h"

void siftDown(int numbers[], int root, int bottom);


void insertsort_int(register int *v, register unsigned long n)
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





void insertsort
(
	register void *v, 
	register unsigned long n, 
	register size_t size, 
	register int (*cmp)(void *, void *)
)
{
	register void *actual;
	register void *anterior = v;
	register void *last = v + (n*size);

	for(actual = v+size; actual < last; actual+=size){
		anterior = actual-size;
		while((anterior >= v) && (cmp(anterior, anterior+size) > 0))
		{
			swap(anterior, anterior+size, size);
			anterior-=size;
		}
	}
}











void med3_int(register int *v, register unsigned long n)
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


void _quicksort_int(register int *v, register unsigned long n)
{
	if(__quicksort_int_umbral>=n){
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

	_quicksort_int(v, m);
	_quicksort_int(j+1, n-(m+1));
}

void quicksort_int
(
	register int *v, 
	register unsigned long n, 
	register int umbral
)
{
	__quicksort_umbral = umbral;
	_quicksort_int(v, n);
	if(umbral>=1) insertsort_int(v, n);
}







void med3
(	
	register void *v, 
	register unsigned long n, 
	register unsigned long size, 
	register int (*cmp)(void *, void *)
)
{
	register void *min = v+(size*((n-1)>>1));
	register void *med = v;
	register void *max = v+(size*(n-1));
	
	if(cmp(min,med) > 0) swap(min, med, size);
	if(cmp(med,max) > 0) swap(med, max, size);
	if(cmp(min,med) > 0) swap(min, med, size);
}
void _quicksort
(
	register void *v, 
	register unsigned long n, 
	register size_t size, 
	register int (*cmp)(void *, void *)
)
{

	register void *i = v;
	register void *j = v+((n-1)*size);
	register int m;

	if(__quicksort_umbral>=n) {
		return;
	}

	//Calcular la mediana
	register void *min = v+(size*((n-1)>>1));
	register void *med = v;
	register void *max = v+(size*(n-1));
	
	if(cmp(min,med) > 0) swap(min, med, size);
	if(cmp(med,max) > 0) swap(med, max, size);
	if(cmp(min,med) > 0) swap(min, med, size);

	//Separar elementos por el pivote
	do
	{
		do { i+=size; } while(cmp(i, v) < 0);
		do { j-=size; } while(cmp(j, v) > 0);
		swap(i, j, size);
	}
	while(j>i);

	swap(i, j, size);
	swap(v, j, size);
	
	m = (j-v)/size;

	_quicksort(v, m, size, cmp);
	_quicksort(j+size, n-(m+1), size, cmp);
	
}
void quicksort
(	register void *v, 
	register int umbral, 
	register unsigned long n, 
	register size_t size, 
	register int (*cmp)(void *, void *)
)
{
	if(cmp == NULL){
		quicksort_int((int*)v, n, umbral);
		return;
	}
	_quicksort(v, n, size, cmp);
	if(umbral>=1) insertsort(v, n, size, cmp);
}

void heapSort(int numbers[], int array_size) {
  int i, temp;
 
  for (i = (array_size / 2); i >= 0; i--) {
    siftDown(numbers, i, array_size - 1);
  }
 
  for (i = array_size-1; i >= 1; i--) {
    // Swap
    temp = numbers[0];
    numbers[0] = numbers[i];
    numbers[i] = temp;
 
    siftDown(numbers, 0, i-1);
  }
}
 
void siftDown(int numbers[], int root, int bottom)
{
  int maxChild = root * 2 + 1;
 
  // Find the biggest child
  if(maxChild < bottom) {
    int otherChild = maxChild + 1;
    // Reversed for stability
    maxChild = (numbers[otherChild] > numbers[maxChild])?otherChild:maxChild;
  } else {
    // Don't overflow
    if(maxChild > bottom) return;
  }
 
  // If we have the correct ordering, we are done.
  if(numbers[root] >= numbers[maxChild]) return;
 
  // Swap
  int temp = numbers[root];
  numbers[root] = numbers[maxChild];
  numbers[maxChild] = temp;
 
  // Tail queue recursion. Will be compiled as a loop with correct compiler switches.
  siftDown(numbers, maxChild, bottom);
}

/*
void mergesort

void bubblesort
*/
