/* 
 *  AUTORES:
 * 	* Carlos Pérez Ramil
 * 	* Rodrigo Arias Mallo
 * 
 *  GRUPO:
 * 	2.3.2
 * 
 *  HORARIO:
 * 	Viernes de 8:30 a 10:30
 */

#include "procesos.h"
#include "global.h"
#include "../lib/proc.h"
#include "priority.h"


int cmd_procesos(char **arg)
{
	char ind;
	int len = PROC_NSTATUS;

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

	if(n==0) return 0;
	
	char time_string[50];
	struct tm *tm_tiempo;
	printf("PID    PRI STAT TIME                  SIG/RET CMD\n");

	for(i=0; i<list_proc->n; i++){

		p = proc[i];
		proc_refresh(p);

		if((ind<len) && (!ISPROCSTATUS(p->status, ind))) continue;

		tm_tiempo = localtime(&(p->time));
		strftime (time_string, 
			sizeof(time_string), 
			"%d %b %Y %H:%M:%S", 
			tm_tiempo
		);

		int sig_ret = 0;
		if(ISPROCSTATUS(p->status, PROC_TERM))
		{
			sig_ret = WEXITSTATUS(p->status);
		}
		else if(ISPROCSTATUS(p->status, PROC_SIG))
		{
			sig_ret = WTERMSIG(p->status);
		}
		else if(ISPROCSTATUS(p->status, PROC_STOP))
		{
			sig_ret = WSTOPSIG(p->status);
		}

		printf("%-6d %3d %4s %-21s %7d %s\n", 
			p->pid, 
			p->prio, 
			GETPROCSTATUS(p->status), 
			time_string, 
			sig_ret,
			p->cmd
		);
	}
	
	return 0;
}
