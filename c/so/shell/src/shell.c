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

#include <string.h>
#include "../lib/entrada.h"
#include "../lib/parametros.h"
#include "../lib/usuario.h"
#include "../lib/path.h"
#include "../src/help.h"
#include "../src/comandos.h"
#include "../src/prog.h"
#include "shell.h"
#include "../lib/list.h"
#include "../src/borraprocesos.h"

list_t list_proc;
list_t list_mem;
int salir_cmd;

int ejecutar(char **arg){
	int i = 0;
	int se_ejecuto = 0;
	if(!arg[0]){
		//printf("Error en obtener_argumentos\n");
		return -1;
	}
	
	while(lista_cmd[i].pfunc)
	{
		if(strcmp(lista_cmd[i].name, arg[0])==0)
		{
			lista_cmd[i].pfunc(arg);
			se_ejecuto=1;
			break;
		}
		i++;
	}
	if(!se_ejecuto)
	{
		cmd_prog(arg);
		//printf("%s: no se encontró la orden.\n", arg[0]);
		
	}
	return 0;
}

void global_init()
{
	salir_cmd = 0;
	list_init(&list_proc, LIST_NO_CLEAR);
	list_init(&list_mem, LIST_CLEAR);
}

void global_free()
{

	list_free(list_proc);
	list_free(list_mem);
}

int main(int argc, char **argv)
{
	char *linea;
	printf("%s\n", INTRO_TXT);
	global_init();

	while(!salir_cmd)
	{
		char *path = obtener_path();
		char *pc = nombre_pc();
		printf("%s[%s]:%s$ ", nombre_login(), pc, path);
		//Salir si pulsamos CTRL+D o introducimos EOF
		if((linea=leer_linea(stdin))==NULL){
			printf("\n");
			
			free(path);
			free(pc);
			exit(0);
		}
		char **arg = obtener_argumentos(linea);
		if(!arg) return -1;
		
		ejecutar(arg);
		
		free(path);
		free(pc);
		free(linea);
		limpiar_argumentos(arg);
	}
	
	global_free();

	return 0;
}
