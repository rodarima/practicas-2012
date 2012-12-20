#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "crono.h"
#include "adjust.h"
#include "cotas.h"
#include "graph.h"
#include "prim.h"
#include <string.h>

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
		
		
		r.k = PRIM_K;

		timeof(r.t, r.k, prim(m, n, nearest, distance, mst), matrix_init(m, n), );

		r.sub  = cota_n_pow_1_9(r.n, r.t);
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
	print_cotas("n^1.9", "n^2", "n^2.1");
	estimate(times, size);



	free(times);
}

int prueba1_prim()
{
	int i, j;
	int n = 5;
	int **m = matrix_create(n);
	int *nearest = malloc(n*sizeof(int));
	int *distance = malloc(n*sizeof(int));
	struct edge *mst = (struct edge *)malloc((n-1)*sizeof(struct edge));
	if ((!nearest)||(!distance)||(!mst)||(!m)) {
		printf("Ha ocurrido un error en malloc");
		return -1;
	}
	
	int m1[] = { 0,1,8,4,7,1,0,2,6,5,8,2,0,9,5,4,6,9,0,3,7,5,5,3,0 };

	for (i = 0; i < n; i++)
	{
		memcpy(m[i], m1+(i*n), n*sizeof(int));
	}


	printf("Matriz de adyacencia:\n");
	for (i=0; i<n; i++) {
		for (j=0; j<n; j++) {
			printf("%d ", m[i][j]);
		}
		printf("\n");
	}

	double t;
 	int k=100000;
  	timeof(t, k, prim(m, n, nearest, distance, mst),,);
   	printf("Tiempo = %f k = %d\n", t, k);
		
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
	return 0;
}

int main(int argc, char **arg)
{
	//prueba1_prim();

	srand(time(NULL));
	table_prim(128, 4096, 2);

	return 0;
}
