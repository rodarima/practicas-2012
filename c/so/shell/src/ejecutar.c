#include "ejecutar.h"
#include "help.h"
#include "priority.h"

int cmd_ejecutar(char **arg)
{
	if(arg[1]==NULL) {
		printf("Faltan argumentos\n");
		show_help(arg[0]);
		return -1;
	}
	
	int arg_count = 2;
	while (arg[arg_count]!=NULL) {
		arg_count++;
	}
	
	char *last_arg = arg[arg_count-1];
	if(last_arg[0]=='@') {
		arg[arg_count-1] = NULL;
		int prio = atoi(last_arg+1);
		if(set_priority(0, prio) != 0) return -1;
	}
	
	if(execvp(arg[1], arg+1)) {
		perror("Error al ejecutar");
		return -1;
	}
	
	//Nunca llega aquí
	return 0;
}
