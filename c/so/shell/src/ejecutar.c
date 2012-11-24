#include "ejecutar.h"
#include "help.h"
#include "priority.h"
#include "../lib/arg_prio.h"

int cmd_ejecutar(char **arg)
{
	if((arg[1]==NULL) || arg[1][0] == '@') {
		printf("Faltan argumentos\n");
		show_help(arg[0]);
		return -1;
	}
	
	char *prio = get_arg_prio(arg+1);

	if(prio)
	{
		int p = atoi(prio);
		if(set_priority(0, p) != 0) return -1;
	}
	
	if(execvp(arg[1], arg+1)) {
		perror("Error al ejecutar");
		return -1;
	}
	
	//Nunca llega aquí
	return 0;
}
