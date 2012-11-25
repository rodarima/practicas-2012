#include "proc.h"
#include "../src/priority.h"

void proc_refresh(struct proc_t *p)
{

	
	int s;
	int w = wait4(p->pid, &s, WNOHANG|WUNTRACED|WCONTINUED, &(p->ru));
	if( w == -1)
	{
		// El proceso ya no existe o no se puede acceder a su informacion
		printf("No existe\n");
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