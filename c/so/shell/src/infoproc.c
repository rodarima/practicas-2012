#include "infoproc.h"
#include "help.h"

int infoproc(struct proc_t *p)
{
	char time_string[50];
	struct tm *tm_tiempo;
	
	proc_refresh(p);
	
	tm_tiempo = localtime(&(p->time));
	strftime (time_string, 
		sizeof(time_string), 
		"%d %b %Y %H:%M:%S", 
		tm_tiempo
	);

	printf("PID   PRI STAT TIME                  CMD\n");

	printf("%5d %3d %4s %-21s %s\n", 
		p->pid, 
		p->prio, 
		GETPROCSTATUS(p->status), 
		time_string, 
		p->cmd
	);

	struct rusage *r = &(p->ru);
	printf("\n");
	printf("User CPU:	%ld.%06ld\n", r->ru_stime.tv_sec, r->ru_stime.tv_usec);
	printf("System CPU:	%ld.%06ld\n", r->ru_utime.tv_sec, r->ru_utime.tv_usec);
	printf("\n");
	printf("Max. resident set size: %ld\n", r->ru_maxrss);
	printf("Shared memory size: 	%ld\n", r->ru_ixrss);
	printf("Unshared data size: 	%ld\n", r->ru_idrss);
	printf("Unshared stack size:	%ld\n", r->ru_isrss);
	printf("Page reclaims:		%ld\n", r->ru_minflt);
	printf("Page faults:		%ld\n", r->ru_majflt);
	printf("Swaps:			%ld\n", r->ru_nswap);
	printf("Block input ops.:	%ld\n", r->ru_inblock);
	printf("block output ops.:	%ld\n", r->ru_oublock);
	printf("IPC messages sent:	%ld\n", r->ru_msgsnd);
	printf("IPC messages received:	%ld\n", r->ru_msgrcv);
	printf("Signals received:	%ld\n", r->ru_nsignals);
	printf("Vol. context switches:	%ld\n", r->ru_nvcsw);
	printf("Inv. context switches:	%ld\n", r->ru_nivcsw);

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
