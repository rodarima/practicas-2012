#include "parametros.h"

/* 
 * Devuelve una estructura args con los argumentos de str, 
 * la cadena original queda INTACTA :)
 */
char **obtener_argumentos(char *str)
{
	char ** arg = NULL;
	arg = malloc(sizeof(char *));
	
	if(!arg){
		perror("Algo ha ido mal en malloc");
	}
	
	arg[0] = NULL;
	
	if(!str){
		return arg;
	}
	
	
	int count = 0;
	
	char *p = strtok (str, ARGS_DELIM);
	while (p != NULL)
	{
		arg[count] = p;
		count++;
			
		p = strtok (NULL, ARGS_DELIM);
		
		arg = realloc(arg, sizeof(char *) * (count + 1));
		if(!arg){
			perror("Algo ha ido mal en realloc");
			return NULL;
		}
		arg[count] = NULL;
	}
	
	return arg;
	
}

/*
char **obtener_argumentos2(char *s)
{
	if(!s) return NULL;
	
	char *str = strdup(s);
	if(!str){
		perror("strdup ha fallado.");
		return NULL;
	}
	int count = 0;
	char **argv = NULL;
	
	char *p = strtok (str, ARGS_DELIM);
	while (p != NULL)
	{
		argv = realloc(argv, sizeof(char *) * (count + 1));
		if(!argv){
			perror("Realloc ha fallado.");
			return NULL;
		}
		*(argv + count)=p;
		count++;
			
		p = strtok (NULL, ARGS_DELIM);
	}
	
	struct args *argumentos = malloc(sizeof(struct args));
	argumentos->argv = argv;
	argumentos->argc = count;
	argumentos->str = str;
	return argumentos;
	
}
*/

int limpiar_argumentos(char **arg)
{
	if(!arg) return -1;
	free(arg);
	
	return 0;
}


/*
int limpiar_argumentos2(struct args *arg)
{
	if(!arg) return -1;
	free(arg->argv);
	free(arg->str);
	free(arg);
	return 0;
}
*/
