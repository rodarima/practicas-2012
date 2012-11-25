#include "infoproc.h"
#include "help.h"

int infoproc(struct proc_t *p)
{
	proc_refresh(p);
	
	printf("PID   PRI STAT TIME          CMD\n");
	printf("%5d %3d %4s %lu %s\n", 
		p->pid, 
		p->prio, 
		GETPROCSTATUS(p->status), 
		p->time, 
		p->cmd
	);
	
	return 0;
}

int cmd_infoproc(char **arg)
{
	struct proc_t *p = NULL;
	int pid, i;
	
	if(arg[1]==NULL) {
		show_help(arg[0]);
		return -1;
	}
	
	pid = atoi(arg[1]);
	for(i=0; i<(list_proc->n); i++) {
		p = list_get(list_proc, (size_t)i);
		if(p->pid!=pid) {
			p = NULL;
		}
	}
	
	if(p==NULL) {
		printf("No se ha encontrado el pid %d en la lista.\n", pid);
	}else {
		infoproc(p);
	}
	
	return 0;
}
