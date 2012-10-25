#include "pid.h"

int cmd_pid(char **arg)
{
	printf("El PID del proceso padre es %d, el actual %d.\n", 
								getppid(), 
								getpid());
	return 0;
}

