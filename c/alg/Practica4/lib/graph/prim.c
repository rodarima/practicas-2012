#include "prim.h"
#include <limits.h>
#include <stdio.h>

/*
 * ALGORITMO DE PRIM
 * Objetivo: Hallar el árbol de recubrimiento mínimo de un grafo dado
 * 
 * matrix:   Es la matriz de adyacencia que representa el grafo
 * n:	     Número de nodos del grafo
 * nearest:  Vector que relaciona cada uno de los nodos del grafo  (el índice del
 * 	     vector) con su nodo más próximo  perteneciente  al árbol que se está
 * 	     construyendo (el valor almacenado)
 * distance: Vector que almacena para cada nodo la distancia mínima al árbol que
 * 	     se está construyendo,  o lo que es lo mismo,  el peso de la  arista 
 * 	     que lo une con su nodo más próximo.
 * mst:	     Vector que va guardando las aristas que se añaden para formar el 
 * 	     árbol de recubrimiento mínimo (minimum spanning tree)
 * 
 * NOTA: Los vectores nearest y distance deben ser de tamaño n
 * 	 El vector mst debe ser de tamaño n-1 (nº aristas)
 */	

void prim(int **matrix, int n, int *nearest, int *distance, struct edge *mst)
{
	register int i;
	register int j;
	register int min;		//Peso mínimo contenido en distance
	register int selected = 0;	//Nº nodo que determinará la arista seleccionada 
	
	distance[0] = -1;	//Tomamos siempre el nodo 0 como inicial
	for (i=1; i<n; i++) {
		nearest[i] = 0;
		distance[i] = matrix[0][i];
	}
	
	for (i=0; i<(n-1); i++) {
		min = INT_MAX;
		for (j=1; j<n; j++) {
			if ((distance[j]>=0)&&(distance[j]<min)) {
				min = distance[j];
				selected = j;
			}
		}
		mst[i].x = nearest[selected];
		mst[i].y = selected;
		mst[i].weight = min;
		distance[selected] = -1;
		for (j=1; j<n; j++) {
			if (matrix[selected][j] < distance[j]) {
				distance[j] = matrix[selected][j];
				nearest[j] = selected;
			}
		}
	}	
}
