#include "prog.h"

int cmd_prog(char **arg)
{	
	int pid, status;
	int arg_count = 0;
	switch (pid=fork()) {
		
		case -1: perror("Error en fork");
			 return -1;
			 
		case 0: while (arg[arg_count]!=NULL) {
				arg_count++;
			}
			
			char *last_arg = arg[arg_count-1];
			if(last_arg[0]=='@') {
				setpriority(PRIO_PROCESS, 0, atoi(last_arg+1));
				arg[arg_count-1] = NULL;
			}
			
			if(execvp(arg[0], arg)) {
				perror("Error al ejecutar");
				exit(-1);
			}
			
		default: waitpid(pid, &status, 0);
	}
	
		
	return 0;
}
