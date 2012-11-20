
#include "fork.h"

int cmd_fork(char **arg)
{
	int pid;
	int stat;
	
	switch (pid=fork()) {
		
		case -1: perror("Error en fork");
			 return -1;
			 
		case 0: break;				//Es el hijo
		
		default: waitpid(pid, &stat, 0);	//Es el padre
	}
	
	return 0;
}
