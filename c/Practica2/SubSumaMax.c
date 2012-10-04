#include <stdio.h>

int sumaSubMax2(int v[], int n);
int sumaSubMaxAux(int v[], int izq, int der);
int max(int a, int b, int c);

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
	int v[] = {-2,-1,-9,-7,-1};
	int n = 5;
	printf("%d\n", sumaSubMax2(v, n));
	return 0;
}
