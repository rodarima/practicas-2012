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

#include "help.h"
#include "comandos.h"

int cmd_help(char **arg)
{
	extern struct cmd_t lista_cmd[];
	if(arg[1]==NULL){
		printf("Comandos disponibles:\n");
		int i;
		for(i=0; lista_cmd[i].name; i++){
			printf("%s ", lista_cmd[i].name);
		}
		printf("\n");
	}else if(arg[2]==NULL){
		int i=0;
		int se_ejecuto = 0;
		while(lista_cmd[i].name)
		{
			if(strcmp(lista_cmd[i].name, arg[1])==0)
			{
				printf("%s\n", lista_cmd[i].use);
				se_ejecuto=1;
				break;
			}
			i++;
		}
		if(!se_ejecuto)
		{
			printf("%s: no se encontró el comando.\n", arg[1]);
			
		}
	}
	else{
		printf("Uso: help [COMANDO]\n");
	}
		
		
	return 0;
}

