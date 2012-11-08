#include <stdio.h>
#include <string.h>
#include <sys/time.h>
#include <stdlib.h>
#include "sort.h"

typedef struct persona
{
	int edad;
	char* nombre;
}t_persona;

int cmp_int(register void *a, register void *b){
	if(*((int*)a)<*((int*)b)) return -1;
	if(*((int*)a)>*((int*)b)) return 1;
	return 0;
}

int cmp_double(void *a, void *b){
	double *pa = (double *)a;
	double *pb = (double *)b;
	
	double na = *pa;
	double nb = *pb;
	
	if(na<nb) return -1;
	if(na>nb) return 1;
	return 0;
}

int cmp_char(void *a, void *b){
	char *pa = (char *)a;
	char *pb = (char *)b;
	
	char na = *pa;
	char nb = *pb;
	
	if(na<nb) return -1;
	if(na>nb) return 1;
	return 0;
}

int cmp_persona(void *a, void *b){
	t_persona *pa = (t_persona *)a;
	t_persona *pb = (t_persona *)b;
	
	if(pa->edad<pb->edad) return -1;
	if(pa->edad>pb->edad) return 1;
	return 0;
}

double u_sec()
{
	struct timeval t;
	if (gettimeofday(&t, 0) < 0 ) return 0.0;
	return (t.tv_usec + t.tv_sec * 1000000.0);
}

/*
double timeof(void (*f)(void *), void *s)
{
	double temp = u_sec();
	f(s);
	return u_sec() - temp;
}
*/

#define MAX 1000000
#define NMAX (1024*32)
#define REP 1000
#define UMBRAL 15

int main(int argc, char **argv)
{

/*

	int numeros[] = { 
		7,5,9,6,8,0,3,1,2,4,
		8,9,2,0,4,5,1,7,3,6,
		4,6,0,8,5,9,2,3,7,1,
		2,1,9,7,0,5,4,6,8,3,
		8,5,1,4,7,6,9,0,3,2,
		7,9,4,8,6,5,2,3,0,1,
		9,8,7,6,5,4,3,2,1,0,
		0,1,2,3,4,5,6,7,8,9};
	

	//int numeros[] = { 1, 3, 5, 2, 6, 7, 4, 8, 0, 9 };
	int i;

	int nnum = sizeof(numeros)/sizeof(int);

	for(i=0; i<nnum; i++) printf("%d ", numeros[i]);
	printf("\n");

	//insertsort(numeros, nnum, sizeof(int), cmp_int);
	//insertsort_int(numeros, nnum);
	quicksort(numeros, 1000, nnum, sizeof(int), NULL);

	for(i=0; i<nnum; i++) printf("%d ", numeros[i]);
	printf("\n");

*/



	int *numeros;
	int i,j;
	double t;

	numeros = malloc(sizeof(int)*NMAX);
	
	t = 0;
	for(j=0; j<REP; j++){

		for(i=0; i<NMAX; i++){
			numeros[i] = rand();
		}

		double t1 = u_sec();

		qsort(numeros, NMAX, sizeof(int), (__compar_fn_t)cmp_int);

		t1 = u_sec() - t1;
		t+=t1;

	}
	t=t/REP;

	printf("qsort glib \t u=%d, n=%d: %fus (%f)us/n\n",
			UMBRAL, 
			NMAX, 
			t, 
			t/NMAX);
	
	t = 0;
	for(j=0; j<REP; j++){

		for(i=0; i<NMAX; i++){
			numeros[i] = rand();
		}

		double t1 = u_sec();

		quicksort(numeros, UMBRAL, NMAX, sizeof(int), cmp_int);
		
		t1 = u_sec() - t1;
		t+=t1;

	}
	t=t/REP;

	printf("quicksort\t u=%d, n=%d: %fus (%f)us/n\n", 
			UMBRAL, 
			NMAX, 
			t, 
			t/NMAX);

	t = 0;
	for(j=0; j<REP; j++){

		for(i=0; i<NMAX; i++){
			numeros[i] = rand();
		}

		double t1 = u_sec();

		quicksort(numeros, UMBRAL, NMAX, sizeof(int), NULL);
		

		t1 = u_sec() - t1;
		t+=t1;

	}
	t=t/REP;

	printf("quicksortbin\t u=%d, n=%d: %fus (%f)us/n\n", 
			UMBRAL, 
			NMAX, 
			t, 
			t/NMAX);

	t = 0;
	for(j=0; j<REP; j++){

		for(i=0; i<NMAX; i++){
			numeros[i] = rand();
		}

		double t1 = u_sec();

		quicksort_int(numeros, NMAX, UMBRAL);
		
		t1 = u_sec() - t1;
		t+=t1;

	}
	t=t/REP;

	printf("quicksort_int\t u=%d, n=%d: %fus (%f)us/n\n", 
			UMBRAL, 
			NMAX, 
			t, 
			t/NMAX);

	t = 0;
	for(j=0; j<2; j++){

		for(i=0; i<NMAX; i++){
			numeros[i] = rand();
		}

		double t1 = u_sec();

		insertsort_int(numeros, NMAX);
		

		t1 = u_sec() - t1;
		t+=t1;

	}
	t=t/2;

	printf("insertsort_int\t u=%d, n=%d: %fus (%f)us/n\n", 
			UMBRAL, 
			NMAX, 
			t, 
			t/NMAX);



/*
	t = 0;
	for(i=0; i<NMAX; i++){
		numeros[i] = rand();
	}

	double t1 = u_sec();

	//qsort(numeros, NMAX, sizeof(int), cmp_int);
	//quicksort(numeros, 1, NMAX, sizeof(int), cmp_int);
	insertsort(numeros, NMAX, sizeof(int), cmp_int);
	

	t1 = u_sec() - t1;
	t+=t1;

	printf("insertsort: %fus (%f)us/n\n", t, t/NMAX);

	free(numeros);
*/
	return 0;
}
