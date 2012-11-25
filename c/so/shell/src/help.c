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

void show_help(char *command)
{
	int i = 0;
	int se_ejecuto = 0;
	while(lista_cmd[i].name)
	{
		if(strcmp(lista_cmd[i].name, command)==0)
		{
			printf("Uso: %s\n", lista_cmd[i].use);
			se_ejecuto=1;
			break;
		}
		i++;
	}
	if(!se_ejecuto)
	{
		printf("%s: no se encontró el comando.\n", command);
		
	}
}


int cmd_help(char **arg)
{
	extern struct cmd_t lista_cmd[];
	if(arg[1]==NULL){
		printf("Comandos disponibles: ");
		int i;
		for(i=0; lista_cmd[i].name; i++){
			printf("%s", lista_cmd[i].name);
			if(lista_cmd[i+1].name) printf(", ");
		}
		printf("\n");
	}else if(arg[2]==NULL){
		show_help(arg[1]);
	}
	else{
		show_help(arg[0]);
	}
		
		
	return 0;
}

