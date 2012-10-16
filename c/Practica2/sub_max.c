#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "tiempo.h"
#include "tabla.h"
#include "cotas.h"
//s
//Solucion: T/n * log n
//

typedef int vector[5];

int sumaSubMax1 (int v[], int n);
int sumaSubMax2(int v[], int n);
int sumaSubMaxAux(int v[], int izq, int der);
int max(int a, int b, int c);


int sumaSubMax1 (int v[], int n){
	int sumaMax = 0;
	int i;
	for (i=0; i<n; i++) {
		int estaSuma = 0;
		int j;
		for (j=i; j<n; j++) {
			estaSuma = estaSuma + v[j];
			if (estaSuma > sumaMax) sumaMax = estaSuma;
		}
	}
	return sumaMax;
}


int sumaSubMax2(int v[], int n){
	return sumaSubMaxAux(v,0,n-1);
}

int max(int a, int b, int c){
	if((a>=b)&&(a>=c)) return a;
	else if((b>=a)&&(b>=c)) return b;
	else return c;
}

int sumaSubMaxAux(int v[], int izq, int der){
	if(izq == der){
		if(v[izq] > 0) return v[izq];
		else return 0;
	}
	else{
		int centro = (izq + der) / 2;
		int sumDer = sumaSubMaxAux(v, centro+1, der);
		int sumIzq = sumaSubMaxAux(v, izq, centro);

		int sumBordeDer = 0;
		int sumAux = 0;
		int i;
		for(i=centro+1; i<=der; i++){
			sumAux = sumAux + v[i];
			if( sumAux > sumBordeDer ) sumBordeDer = sumAux;
		}

		sumAux = 0;
		int sumBordeIzq = 0;
		for(i = centro; i>=izq; i--){
			sumAux = sumAux + v[i];
			if (sumAux > sumBordeIzq) sumBordeIzq = sumAux;
		}
		return max(sumIzq, sumDer, sumBordeIzq + sumBordeDer);

	}
}

int crear_vector(int **v, int n){
	(*v) = malloc(n*sizeof(int));
	if(v==NULL) return -1;
	else return 0;
}

int destruir_vector(int *v, int n){
	free(v);
	return 0;
}

int rellenar_vector(int *v, int n) {
	int i;
	for (i=0; i < n; i++)
		v[i] = (rand() % 21) - 10;
	return 0;
}

double cota1_sub(int n, double t)
{
	double nd = n;
	return t/pow(nd, 1.6);
}
double cota1(int n, double t)
{
	double nd = n;
	return t/pow(nd, 1.8);
}
double cota1_sobre(int n, double t)
{
	double nd = n;
	return t/pow(nd, 2.2);
}


double cota2_sub(int n, double t)
{
	double nd = n;
	return t/nd;
}
double cota2(int n, double t)
{
	double nd = n;
	return t/(nd*log(nd));
}
double cota2_sobre(int n, double t)
{
	double nd = n;
	return t/pow(nd, 1.1);
}

int main(int argc, char **argv)
{
	srand((int)microsegundos());

	struct tabla_t tabla_t1 = {
		"Suma Subsecuencia Máxima 1", 	//titulo
		
		1, 		//min
		65536,	 	//max
		2,  		//paso
		10000,		//k
		
		sumaSubMax1, 	//funcion
		crear_vector,	//crear
		rellenar_vector,//rellenar
		destruir_vector,//destruir
		
		cota1_sub,	//subestimada
		cota1, 		//estimada
		cota1_sobre	//sobrestimada
	};
	
	
	imprimir_tabla(&tabla_t1);
	
	
	struct tabla_t tabla_t2 = {
		"Suma Subsecuencia Máxima 2", 	//titulo
		
		32, 		//min
		65536,	 	//max
		2,  		//paso
		10000,		//k
		
		sumaSubMax2, 	//funcion
		crear_vector,	//crear
		rellenar_vector,//rellenar
		destruir_vector,//destruir
		
		cota2_sub,	//subestimada
		cota2, 		//estimada
		cota2_sobre	//sobrestimada
	};
	
	
	imprimir_tabla(&tabla_t2);
	
	/*vector tabla[6] = {{-9, 2, -5, -4, 6},{4, 0, 9, 2, 5},{-2, -1, -9, -7, -1},{9, -2, 1, -7, -8},{15, -2, -5, -4, 16}, {7, -5, 6, 7, -7}};

	int i;
	for (i=0; i<6; i++) {
		int entro;
		double f = medir_tiempo_fvector(&sumaSubMax1, tabla[i], 5, &entro);
		printf("%f  ---  %d\n", medir_tiempo_fvector(&sumaSubMax1, tabla[i], 5, &entro), sumaSubMax2(tabla[i], 5));
	}
*/
	//medir_tiempo_fvector(&sumaSubMax1, tabla[0], 5);

	return 0;
}
