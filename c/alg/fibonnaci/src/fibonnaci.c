#include <stdio.h>
#include <sys/time.h>
#include <math.h>


/* obtiene la hora actual en microsegundos */
double microsegundos() {
	struct timeval t;
	if (gettimeofday(&t, 0) < 0 ) return 0.0;
	return (t.tv_usec + t.tv_sec * 1000000.0);
}

int fib1(int n){
	if(n<2) return n;
	else return (fib1(n-1)+fib1(n-2));
}
int fib2(int n){
	int i=1, j=0;
	int k;
	for(k = 1; k<=n; k++){
		j=i+j;
		i=j-i;
	}
	return j;
}
int fib3(int n){
	int i=1, j=0, k=0, h=1, t=0;
	
	while(n>0){
		if(n%2){
			t=j*h;
			j=i*h + j*k + t;
			i=i*k + t;
		}
		t = h * h;
		h = 2*k*h + t;
		k = k*k +t;
		n = n/2;
	}
	return j;
	
}
/*
void test(int n){
	int i;
	for(i=0; i<n; i++){
		printf("fib1: %d ", fib1(i));
		printf("fib2: %d ", fib2(i));
		printf("fib3: %d\n", fib3(i));
	}
}
*/
void medir_f1(int n){
	double t1, t2, t12, t;
	double x, y, z;
	int entro = 0;
	t1 = microsegundos();
	fib1(n);
	t2 = microsegundos();
	t = t2-t1;
	int k=10000;
	if(t<500){
		entro=1;
		int i=0;
		
		t1 = microsegundos();
		for(i=0; i<k; i++){
			fib1(n);
		}
		t2 = microsegundos();
		
		
		t12=t2-t1;
		
		t=t12/((double)k);
	}
	
	x = t / pow(1.1,n);								//SUBESTIMADA
	y = t / pow((1.0+sqrt(5.0))/2.0, (double)n);	//AJUSTADA
	z = t / pow(2.0, n);							//SOBREESTIMADA
	printf("%9d%15.5f%15.6f%15.6f%15.6f", n, t, x, y, z);
	if(entro){
		printf("%9d\n", k);
	}else{
		printf("\n");
	}
}
void medir_f2(int n){
	double t1, t2, t12, t;
	double x, y, z;
	int entro = 0;
	t1 = microsegundos();
	fib2(n);
	t2 = microsegundos();
	t = t2-t1;
	int k=10000;
	if(t<500){
		entro=1;
		int i=0;
		
		t1 = microsegundos();
		for(i=0; i<k; i++){
			fib2(n);
		}
		t2 = microsegundos();
		
		t12=t2-t1;
		
		t=t12/((double)k);
	}
	
	x = t / pow(n,0.8);							//SUBESTIMADA
	y = t / ((double)n);						//AJUSTADA
	z = t / (((double)n)*(log((double)n)));		//SOBREESTIMADA
	printf("%9d%15.3f%15.6f%15.6f%15.6f", n, t, x, y, z);
	if(entro){
		printf("%9d\n", k);
	}else{
		printf("\n");
	}
}
void medir_f3(int n){
	double t1, t2, t12, t;
	double x, y, z;
	int entro = 0;
	t1 = microsegundos();
	fib3(n);
	t2 = microsegundos();
	t = t2-t1;
	//printf(" t=%f ",t);
	int k=10000;
	if(t<500){
		entro=1;
		int i=0;
		
		t1 = microsegundos();
		for(i=0; i<k; i++){
			fib3(n);
		}
		t2 = microsegundos();
		
		t12=t2-t1;
		
		t=t12/((double)k);
		//printf(" tr=%f ",t);
	}
	
	x = t / sqrt(log(n));	//SUBESTIMADA
	y = t / log(n);			//AJUSTADA
	z = t / pow(n,0.5);		//SOBREESTIMADA
	printf("%9d%15.3f%15.6f%15.6f%15.6f", n, t, x, y, z);
	if(entro){
		printf("%9d\n", k);
	}else{
		printf("\n");
	}
}

int main() {
	int i;
	printf("Tabla fib1:\n");
	printf("        n           t(n)      t(n)/h(n)      t(n)/g(n)      t(n)/f(n)        k\n");
	for(i=2; i<=32; i*=2){
		medir_f1(i);
	}
	printf("                            SUBESTIMADA       ESTIMADA  SOBREESTIMADA         \n");
	printf("\nTabla fib2:\n");
	printf("        n           t(n)      t(n)/h(n)      t(n)/g(n)      t(n)/f(n)        k\n");
	for(i=1000; i<=10000000; i*=10){
		medir_f2(i);
	}
	printf("                            SUBESTIMADA       ESTIMADA  SOBREESTIMADA         \n");

	printf("\nTabla fib3:\n");
	printf("        n           t(n)      t(n)/h(n)      t(n)/g(n)      t(n)/f(n)        k\n");
	for(i=1000; i<=10000000; i*=10){
		medir_f3(i);
	}
	printf("                            SUBESTIMADA       ESTIMADA  SOBREESTIMADA         \n");
}


