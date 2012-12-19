#ifndef PRIM_H
#define PRIM_H


struct edge {
	int x;
	int y;
	int weight;
};

void prim(register int **matrix, register int n, register int *nearest, register int *distance, register struct edge *mst);

#endif
