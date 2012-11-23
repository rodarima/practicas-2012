#include "splano.h"
#include "../lib/proc.h"
#include "global.h"

char *obtener_cmd(char *ini, char *fin)
{
	char *str = malloc(fin - ini);
	memcpy(str, ini, (size_t)(fin-ini));
	return str;
}

int cmd_splano(char **arg)
{
	struct proc_t *p;
	int pid, status;
	time_t t;
	int arg_count = 0;
	while (arg[arg_count]!=NULL) {
		arg_count++;
	}
	char *last_arg = arg[arg_count-1];
	
	if((arg[1]==last_arg)||(arg[1]==NULL)) {
		//show_help(arg[0]);
		return -1;
	}
	
	t = time(0);
	switch (pid=fork()) {
		
		case -1:perror("Error en fork");
			return -1;
		
		case 0: if(last_arg[0]=='@') {
				setpriority(PRIO_PROCESS, 0, atoi(last_arg+1));
				arg[arg_count-1] = NULL;
			}
			
			if(execvp(arg[1], arg+1)) {
				perror("Error al ejecutar");		
			}
			extern int salir_cmd;
			salir_cmd = 1;	
			break;
		
		default:waitpid(pid, &status, WNOHANG|WUNTRACED|WCONTINUED);
			printf("%p\n", list_proc);
			p = list_new(list_proc, sizeof(struct proc_t));
			p->pid = pid;
			p->prio = atoi(last_arg+1);
			p->cmd = obtener_cmd(arg[1], last_arg);
			p->time = t;
			p->status = 0x00;
			SETPROCSTATUS(p->status, PROC_RUN);
			p->sig = 0;
			p->ru = NULL;			 
	}
	
	return 0;	
}
