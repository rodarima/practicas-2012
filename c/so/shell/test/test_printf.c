#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	//void *a = malloc(1000000000);
	void *a = malloc(10);

	printf("0x%016lx\n", (unsigned long)a);

	return 0;
}