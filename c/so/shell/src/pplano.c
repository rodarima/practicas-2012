#include "pplano.h"
#include "help.h"
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "../lib/proc.h"
#include "global.h"

struct proc_t *get_proc_pid(pid_t pid)
{
	int found = 0;
	struct proc_t **p = (struct proc_t **)list_proc->data;
	while((*p) && found)
	{
		if((*p)->pid == pid)
		{
			found++;
		}
		else p++;
	}
	return *p;
}

int cmd_pplano(char **arg)
{
	if(arg[1]==NULL)
	{
		printf("Falta el PID\n");
		show_help("pplano");
		return -1;
	}
	pid_t pid = atoi(arg[1]);
	
	/*if()

	int status;
	waitpid(pid, &status, 0);*/

}