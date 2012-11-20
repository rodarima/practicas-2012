#include "ejecutar.h"

int cmd_ejecutar(char **arg)
{
	if(arg[1]==NULL) {
		printf("Falta un operando\n");
		return -1;
	}
	
	int arg_count = 0;
	while (arg[arg_count]!=NULL) {
		arg_count++;
	}
	
	char *last_arg = arg[arg_count-1];
	if(last_arg[0]=='@') {
		setpriority(PRIO_PROCESS, 0, atoi(last_arg+1));
		arg[arg_count-1] = NULL;
	}
	
	if(execvp(arg[1], arg+1)) {
		perror("Error al ejecutar: ");
		return -1;
	}
	
	return 0;
}
