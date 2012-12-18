#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "crono.h"
#include "adjust.h"
#include "cotas.h"
#include "graph.h"
#include "./lib/graph/prim.h"

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

void matrix_free(int **matrix, int n)
{
	int i;
	for (i=0; i<n; i++) {
		free(matrix[i]);
	}
	free(matrix);	
}

int main(int argc, char **arg)
{
	srand(time(NULL));
	int n = rand() % 10;
	int **m = matrix_create(n);
	int *nearest = malloc(n*sizeof(int));
	int *distance = malloc(n*sizeof(int));
	struct edge *mst = (struct edge *)malloc((n-1)*sizeof(struct edge));
	if ((!nearest)||(!distance)||(!mst)||(!m)) {
		printf("Ha ocurrido un error en malloc");
		return -1;
	}
	matrix_init(m, n);
	
	printf("Matriz de adyacencia:\n");
	int i, j;
	for (i=0; i<n; i++) {
		for (j=0; j<n; j++) {
			printf("%d ", m[i][j]);
		}
		printf("\n");
	}
	
	prim(m, n, nearest, distance, mst);
	
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
