/* 
 *  AUTORES:
 * 	* Carlos Pérez Ramil
 * 	* Rodrigo Arias Mallo
 * 
 *  GRUPO:
 * 	2.3.2
 * 
 *  HORARIO:
 * 	Viernes de 8:30 a 10:30
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	//void *a = malloc(10000000000000);
	//void *a = malloc(10);
	char b[] = "0olita";

	//printf("0x%016lx\n", (unsigned long)a);
	printf("%02x", b[0]);

	return 0;
}
