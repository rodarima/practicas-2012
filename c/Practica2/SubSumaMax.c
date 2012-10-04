#include <stdio.h>

//Solucion: T/n * log n

typedef int vector[5];

int sumaSubMax1 (int v[], int n);
int sumaSubMax2(int v[], int n);
int sumaSubMaxAux(int v[], int izq, int der);
int max(int a, int b, int c);


int sumaSubMax1 (int v[], int n)	{
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

int main(int argc, char **argv)
{
	vector tabla[6] = {{-9, 2, -5, -4, 6},{4, 0, 9, 2, 5},{-2, -1, -9, -7, -1},{9, -2, 1, -7, -8},{15, -2, -5, -4, 16}, {7, -5, 6, 7, -7}};

	int i;
	for (i=0; i<6; i++) {
		printf("%d  ---  %d\n", sumaSubMax1(tabla[i], 5), sumaSubMax2(tabla[i], 5));
	}

	return 0;
}
