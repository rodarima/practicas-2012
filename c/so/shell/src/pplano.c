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
	struct proc_t **p = (struct proc_t **)list_proc->data;
	while((*p))
	{
		if((*p)->pid == pid) break;
		p++;
	}
	return *p;
}

int cmd_pplano(char **arg)
{
	if(arg[1]==NULL)
	{
		show_help(arg[0]);
		return -1;
	}
	pid_t pid = atoi(arg[1]);
	struct proc_t *p;
	if((p=get_proc_pid(pid)) == NULL)
	{
		printf("El proceso no está en la lista.\n");
	}
	int s;
	int w = wait4(p->pid, &s, 0, &(p->ru));
	if(w==-1)
	{
		perror("wait4 ha fallado");
		return -1;
	}
	
	if(WIFEXITED(s)) {
		SETPROCSTATUS(p->status, PROC_TERM);	
		p->sig_exit = WEXITSTATUS(s);
	}
	else if(WIFSIGNALED(s)) {
		SETPROCSTATUS(p->status, PROC_SIG);
		p->sig_exit = WTERMSIG(s);
	}
	else if(WIFSTOPPED(s)) {
		SETPROCSTATUS(p->status, PROC_STOP);
		p->sig_exit = WSTOPSIG(s);
	}
	else{
		SETPROCSTATUS(p->status, PROC_RUN);
	}
	infoproc(p);
	return 0;
}