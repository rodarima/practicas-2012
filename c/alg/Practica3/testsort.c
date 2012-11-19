#include <stdio.h>
#include <string.h>
#include <sys/time.h>
#include <stdlib.h>

#include "crono.h"
#include "adjust.h"
#include "cotas.h"
#include "sort.h"

#define UMBRAL_START	1
#define UMBRAL_END	100
#define UMBRAL_STEP	10
#define STARTUP_STEPS	512
#define MAX 		1000000
#define NMAX 		(1024*32)
#define REP 		1000
#define UMBRAL 		15

#define get_func_name(f) #f

void vector_int_rand(int *v, int n);
void vector_int_asc(int *v, int n);
void vector_int_desc(int *v, int n);


typedef void (*vector_func_t)(int *, int);
struct vector_func_name_t
{
	vector_func_t f;
	char* name;
};
struct vector_func_name_t vector_funcs[] = 
{
	{ vector_int_rand, "Aleatorio"  },
	{ vector_int_desc, "Descendente"},
	{ vector_int_asc,  "Ascendente" }
};

int cmp_int(register void *a, register void *b){
	if(*((int*)a) < *((int*)b)) return -1;
	if(*((int*)a) > *((int*)b)) return 1;
	return 0;
}

double u_sec()
{
	struct timeval t;
	if (gettimeofday(&t, 0) < 0 ) return 0.0;
	return (t.tv_usec + t.tv_sec * 1000000.0);
}

void rand_init(){
	srand(u_sec());
}

void vector_int_rand(int v[], int n){
	int i;
	for (i = 0; i < n; ++i)
	{
		v[i]=rand();
	}
}

void vector_int_asc(int v[], int n){
	int i;
	for (i = 0; i < n; ++i)
	{
		v[i]=i;
	}
}

void vector_int_desc(int v[], int n){
	int i;
	for (i = 0; i < n; ++i)
	{
		v[i]=n-(i+1);
	}
}

void create_vector(int **v, int n)
{
	(*v) = malloc(n * sizeof(int));
	if(!(*v)){
		perror("Algo falló en malloc");
		exit(1);
	}
}

void free_vector(int *v, int n)
{
	if(!v){
		perror("Algo falló al intentar hacer free");
		exit(1);
	}
	free(v);
}


int steps_to_n(int from, int to, int step)
{
	return (log(to/from)/log(step))+1;
}

void time_quicksort(struct time_row_t *r, int *v, int umbral, vector_func_t f)
{
	timeof(r->t, r->k, 
	//qsort(v, r->n, 4, (__compar_fn_t) cmp_int)
	quicksort_int(v, r->n, umbral)
	//insertsort_int(v, r->n)
	,f(v, r->n), );
}

void table_quicksort(int from, int to, int step)
{

	struct time_row_t r;
	int *v = NULL;
	int i,j,k;
	int size = steps_to_n(from, to, step);
	//printf("%d\n", size);
	time_value *times = malloc(size*sizeof(time_value));

	create_vector(&v, STARTUP_STEPS);
	r.n=STARTUP_STEPS;
	time_quicksort(&r, v, 1, vector_int_rand);
	free_vector(v, STARTUP_STEPS);

	for (j = 0; j < (sizeof(vector_funcs)/sizeof(struct vector_func_name_t)); j++)
	{
		for(i=UMBRAL_START; i<=UMBRAL_END; i*=UMBRAL_STEP)
		{
			k=0;
			printf("Quicksort umbral=%d orden=%s\n", i, vector_funcs[j].name);
			print_head();
			for(r.n=from; r.n<=to; r.n*=step){
				create_vector(&v, r.n);
				
				time_quicksort(&r, v, i, vector_funcs[j].f);

				r.sub = cota_nlog_n_pow_0_9(r.n, r.t);
				r.aj = cota_nlogn(r.n, r.t);
				r.sob = cota_nlog_n_pow_1_1(r.n, r.t);

				print_row(&r);

				free_vector(v, r.n);
				times[k].n = r.n;
				times[k].t = r.t;
				k++;
			}
			printf("\n");
			estimate(times, size);
			printf("\n\n");
		}
	}
	free(times);
}

void time_insertsort(struct time_row_t *r, int *v, vector_func_t f)
{
	timeof(r->t, r->k, 
	//qsort(v, r->n, 4, (__compar_fn_t) cmp_int)
	//quicksort_int(v, r->n, umbral)
	insertsort_int(v, r->n)
	,f(v, r->n), );
}

void table_insertsort(int from, int to, int step)
{
	struct time_row_t r;
	int *v = NULL;
	int j,k;
	int size = steps_to_n(from, to, step);
	//printf("%d\n", size);
	time_value *times = malloc(size*sizeof(time_value));

	r.n=STARTUP_STEPS;
	create_vector(&v, STARTUP_STEPS);
	time_insertsort(&r, v, vector_int_rand);
	free_vector(v, STARTUP_STEPS);

	for (j = 0; j < 2; j++)
	{
		
		k=0;
		printf("Insertsort orden=%s\n", vector_funcs[j].name);
		print_head();
		for(r.n=from; r.n<=to; r.n*=step){
			create_vector(&v, r.n);
			
			time_insertsort(&r, v, vector_funcs[j].f);

			r.sub  = cota_n_pow_1_9(r.n, r.t);
			r.aj = cota_n_pow_2(r.n, r.t);
			r.sob = cota_n_pow_2_1(r.n, r.t);

			print_row(&r);

			free_vector(v, r.n);
			times[k].n = r.n;
			times[k].t = r.t;
			k++;
		}
		estimate(times, size);
	}

	k=0;
	printf("Insertsort orden=%s\n", vector_funcs[2].name);
	print_head();
	for(r.n=from; r.n<=to; r.n*=step){
		create_vector(&v, r.n);
		
		time_insertsort(&r, v, vector_funcs[j].f);

		r.sub = cota_n_pow_0_95(r.n, r.t);
		r.aj = cota_n(r.n, r.t);
		r.sob = cota_n_pow_1_05(r.n, r.t);

		print_row(&r);

		free_vector(v, r.n);
		times[k].n = r.n;
		times[k].t = r.t;
		k++;
	}
	estimate(times, size);



	free(times);
}

void ord_ins (int v [], int n){
	insertsort_int(v, n);
}

void rapida_aux(int *v, int u, int n)
{
	quicksort_int(v, n+1, u);
}

void ord_rapida(int v [], int n) {
	rapida_aux(v, 0, n-1);
	if (UMBRAL > 1)
	ord_ins(v, n);
}


int main(int argc, char **argv)
{
	rand_init();
	table_quicksort(128, 32768, 2);
	table_insertsort(128, 32768, 2);

	/*struct time_row_t tr;
	int *v = NULL;

	time_value *t = malloc(11*sizeof(time_value));
	int j=0;
	tr.k=MAX_K;
	for(tr.n=512; tr.n<=32768; tr.n*=2){
		create_vector(&v, tr.n);
		t[j].n = tr.n;
		time_quicksort(&tr, v, 15, vector_int_rand);
		t[j].t = tr.t;
		free_vector(v, tr.n);
		j++;
	}

	estimate(t, j, NULL);*/

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

/*

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

*/

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
