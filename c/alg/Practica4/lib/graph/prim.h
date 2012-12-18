#ifndef PRIM_H
#define PRIM_H


struct edge {
	int x;
	int y;
	int weight;
};

void prim(int **matrix, int n, int *nearest, int *distance, struct edge *mst);

#endif
