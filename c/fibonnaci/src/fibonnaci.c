#include <stdio.h>

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

void test(int n){
	int i;
	for(i=0; i<n; i++){
		printf("fib1: %d ", fib1(i));
		printf("fib2: %d ", fib2(i));
		printf("fib3: %d\n", fib3(i));
	}
}

int main(int argc, char **argv)
{
	test(20);
	return 0;
}


