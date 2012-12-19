#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "crono.h"
#include "adjust.h"
#include "cotas.h"
#include "graph.h"
#include "adjust.h"
#include "./lib/graph/prim.h"

#define PRIM_K	1000

int **matrix_create(int n)
{
	int i;
	int **aux;
	
	if ((aux = (int **) malloc(n*sizeof(int *))) == NULL)
		return NULL;
	for (i=0; i<n; i++) {
		if ((aux[i] = (int *) malloc(n*sizeof(int))) == NULL)
			return NULL;
	}
	return aux;
}
/*
void matrix_init(int **matrix, int n)
{
	int i, j;
	for (i=0; i<n; i++) {
		for (j=i+1; j<n; j++) {
			matrix[i][j] = rand() % n + 1;
		}
	}
	
	for (i=0; i<n; i++) {
		for (j=0; j<=i; j++) {
			if (i==j)
				matrix[i][j] = 0;
			else
				matrix[i][j] = matrix[j][i];
		}
	}
}
*/

void matrix_init(int **matrix, int n)
{
	int i, j;
	int r;
	
	for (i=0; i<n; i++) {
		for (j=0; j<=i; j++) {
			if (i==j)
			{
				matrix[i][j] = 0;
			}
			else
			{
				r = rand()%(n+1);

				matrix[i][j] = r;
				matrix[j][i] = r;
			}	
		}
	}
}


void matrix_free(int **matrix, int n)
{
	int i;
	for (i=0; i<n; i++) {
		free(matrix[i]);
	}
	free(matrix);	
}


int steps_to_n(int from, int to, int step)
{
	return (log(to/from)/log(step))+1;
}



void table_prim(int from, int to, int step)
{
	struct time_row_t r;
	int k=0;
	int size = steps_to_n(from, to, step);
	//printf("%d\n", size);
	time_value *times = malloc(size*sizeof(time_value));


	r.k = PRIM_K;
	printf("Prim\n");
	print_head();
	for(r.n=from; r.n<=to; r.n*=step){
		int n = r.n;
		int **m = matrix_create(n);
		int *nearest = malloc(n*sizeof(int));
		int *distance = malloc(n*sizeof(int));
		struct edge *mst = (struct edge *)malloc((n-1)*sizeof(struct edge));
		if ((!nearest)||(!distance)||(!mst)||(!m)) {
			printf("Ha ocurrido un error en malloc");
			return;
		}
		
		
		timeof(r.t, r.k, prim(m, n, nearest, distance, mst), matrix_init(m, n), );

		
		r.sub  = (r.t/((r.n-1)*(r.n-1)));
		r.aj = cota_n_pow_2(r.n, r.t);
		r.sob = cota_n_pow_2_1(r.n, r.t);
		
		print_row(&r);

		free(mst);
		free(distance);
		free(nearest);
		matrix_free(m, r.n);
		times[k].n = r.n;
		times[k].t = r.t;
		k++;
	}
	estimate(times, size);



	free(times);
}


int main(int argc, char **arg)
{
	srand(time(NULL));
	table_prim(8, 4096, 2);

	/*
	int n = 100;
	int **m = matrix_create(n);
	int *nearest = malloc(n*sizeof(int));
	int *distance = malloc(n*sizeof(int));
	struct edge *mst = (struct edge *)malloc((n-1)*sizeof(struct edge));
	if ((!nearest)||(!distance)||(!mst)||(!m)) {
		printf("Ha ocurrido un error en malloc");
		return -1;
	}
	
	
	matrix_init(m, n);

	double t;
 	int k=100000;
  	timeof(t, k, prim(m, n, nearest, distance, mst),,);
   	printf("Tiempo = %f k = %d\n", t, k);

	
	
	matrix_init(m, n);
	
	printf("Matriz de adyacencia:\n");
	int i, j;
	for (i=0; i<n; i++) {
		for (j=0; j<n; j++) {
			printf("%d ", m[i][j]);
		}
		printf("\n");
	}
	

		
	int total_weight = 0;
	printf("\nÁrbol expandido mínimo:\n");
	for (i=0; i<(n-1); i++) {
		printf("(%d, %d) ", mst[i].x, mst[i].y);
		total_weight += mst[i].weight;
	}
	printf("\nPeso total: %d\n", total_weight);
	
	
	free(mst);
	free(distance);
	free(nearest);
	matrix_free(m, n);
	*/
	return 0;
}
