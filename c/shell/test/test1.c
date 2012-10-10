#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "leer_linea.h"

int main(int argc, char **argv)
{
	char * linea;
	while(1){
		printf("shell$ ");
		//Salir si pulsamos CTRL+D o introducimos EOF
		if((linea=leer_linea())==NULL){	
			printf("\n");
			exit(0);
		}
		
		printf("%s\n", linea);
		
		free(linea);
	}
	return 0;
}


