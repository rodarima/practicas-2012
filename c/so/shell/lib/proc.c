#include "proc.h"

void proc_refresh(struct proc_t *p)
{
	int s;
	wait4(p->pid, &s, WNOHANG|WUNTRACED|WCONTINUED, &(p->ru));
	
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
	
	SETPROCSTATUS(p->status, PROC_RUN);	
}
