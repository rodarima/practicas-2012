#include <string.h>
#include "../lib/entrada.h"
#include "../lib/parametros.h"
#include "../lib/usuario.h"
#include "../lib/path.h"
#include "../src/comandos.h"
#include "test_cmd.h"

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
		printf("%s: no se encontró la orden.\n", arg[0]);
		
	}
	return 0;
}
int main(int argc, char **argv)
{
	char *linea;
	salir_cmd = 0;
	while(!salir_cmd)
	{
		char *path = obtener_path();
		char *pc = nombre_pc();
		printf("%s#%s:%s$ ", nombre_login(), pc, path);
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
	return 0;
}
