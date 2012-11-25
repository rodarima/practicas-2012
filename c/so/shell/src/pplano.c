#include "pplano.h"
#include "help.h"
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "infoproc.h"
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
	struct proc_t *p;
	if((p=get_proc_pid(pid)) == NULL)
	{
		printf("El proceso no está en la lista.\n");
	}

	waitpid(pid, &(p->sig_exit), 0);
	infoproc(p);

}