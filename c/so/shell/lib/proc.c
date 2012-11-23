#include "proc.h"

void proc_refresh(struct proc_t *p)
{
	int s;
	wati4(p->pid, &s, WNOHANG|WUNTRACED|WCONTINUED, p->ru);
	
	if(WIFEXITED(s)) {
		SETPROCSTATUS(p->status, PROC_TERM);	
		return;
	}
	if(WIFSIGNALED(s)) {
		SETPROCSTATUS(p->status, PROC_SIG);
		p->sig = WTERMSIG(s);
		return;
	}
	if(WIFSTOPPED(s)) {
		SETPROCSTATUS(p->status, PROC_STOP);
		return;
	}
	
	SETPROCSTATUS(p->status, PROC_RUN);	
}
