#include "procesos.h"
#include "global.h"
#include "../lib/proc.h"
#include "priority.h"

void proc_refresh(struct proc_t *p)
{

	
	int s;
	int w = wait4(p->pid, &s, WNOHANG|WUNTRACED|WCONTINUED, &(p->ru));
	if( w == -1)
	{
		// El proceso ya no existe o no se puede acceder a su informacion
		return;
	}
	if( w == 0)
	{
		get_priority(p->pid, &(p->prio));
		return;
	}
	
	if(WIFEXITED(s)) {
		SETPROCSTATUS(p->status, PROC_TERM);	
		p->sig_exit = WEXITSTATUS(s);
		return;
	}
	if(WIFSIGNALED(s)) {
		SETPROCSTATUS(p->status, PROC_SIG);
		p->sig_exit = WTERMSIG(s);
		return;
	}
	if(WIFSTOPPED(s)) {
		SETPROCSTATUS(p->status, PROC_STOP);
		p->sig_exit = WSTOPSIG(s);
		return;
	}

	if(get_priority(p->pid, &(p->prio)) != 0) return;

	SETPROCSTATUS(p->status, PROC_RUN);
}


int cmd_procesos(char **arg)
{
	char ind;
	int len = sizeof(proc_name_status) / sizeof(char *);

	if(arg[1] != NULL)
	{

		for(ind = 0x00; ind<len; ind++)
		{
			if(strcmp(proc_name_status[(int)ind], arg[1]) == 0){
				break;
			}
		}

	}
	else ind = len;

	int i;
	struct proc_t **proc = (struct proc_t **)list_proc->data;
	struct proc_t *p;
	int n = list_proc->n;
	if(n>0)
	{
		printf("PID   PRI STAT TIME          CMD\n");
		for(i=0; i<list_proc->n; i++){

			p = proc[i];
			proc_refresh(p);

			if((ind<len) && (!ISPROCSTATUS(p->status, ind))) continue;

			printf("%5d %3d %4s %lu %s\n", 
				p->pid, 
				p->prio, 
				GETPROCSTATUS(p->status), 
				p->time, 
				p->cmd
			);
		}
	}
	return 0;
}
