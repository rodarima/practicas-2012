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
#include <string.h>

#include "../lib/entrada.h"
#include "../lib/parametros.h"
#include "../lib/usuario.h"

int main(int argc, char **argv)
{
	char * linea;
	while(1){
		printf("%s$ ", nombre_login());
		//Salir si pulsamos CTRL+D o introducimos EOF
		if((linea=leer_linea(stdin))==NULL){	
			printf("\n");
			exit(0);
		}
		
		printf("Introduciste: %s\n", linea);
		char **arg = obtener_argumentos(linea);
		
		if(!arg){
			printf("Error en obtener_argumentos\n");
			return -1;
		}
		
		int i;
		while(arg[i] != NULL)
		{
			printf("%s\n", arg[i]);
			i++;
		}
		
		free(linea);
		limpiar_argumentos(arg);
	}
	return 0;
}


