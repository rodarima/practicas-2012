#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../lib/entrada.h"
#include "../lib/parametros.h"

int main(int argc, char **argv)
{
	char * linea;
	while(1){
		printf("shell$ ");
		//Salir si pulsamos CTRL+D o introducimos EOF
		if((linea=leer_linea(stdin))==NULL){	
			printf("\n");
			exit(0);
		}
		
		printf("Introduciste: %s\n", linea);
		
		free(linea);
	}
	return 0;
}


