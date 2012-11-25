#include "infoproc.h"
#include "help.h"

int infoproc(struct proc_t *p)
{
	char time_string[50];
	struct tm *tm_tiempo;
	
	proc_refresh(p);
	
	tm_tiempo = localtime(&(p->time));
	strftime(time_string, 
		sizeof(time_string), 
		"%d %b %Y %H:%M:%S", 
		tm_tiempo
		);
		
	printf("PID   PRI STAT TIME          CMD\n");
	printf("%5d %3d %4s %lu %s\n", 
		p->pid, 
		p->prio, 
		GETPROCSTATUS(p->status), 
		time_string, 
		p->cmd
	);
	
	return 0;
}

int cmd_infoproc(char **arg)
{
	struct proc_t **proc = (struct proc_t **)list_proc->data;
	struct proc_t *p;
	int pid, i;
	
	if(arg[1]==NULL) {
		show_help(arg[0]);
		return -1;
	}
	
	pid = atoi(arg[1]);
	for(i=0; i<(list_proc->n); i++) {
		p = proc[i];
		if(p->pid!=pid) {
			p = NULL;
		}else {
			break;
		}
	}
	
	if(p==NULL) {
		printf("No se ha encontrado el pid %d en la lista.\n", pid);
	}else {
		infoproc(p);
	}
	
	return 0;
}
