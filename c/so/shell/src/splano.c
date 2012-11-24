#include "splano.h"
#include "../lib/proc.h"
#include "../lib/arg_prio.h"
#include "global.h"
#include "help.h"
#include "priority.h"
#include <sys/time.h>
#include <sys/resource.h>
#include <errno.h>

char *obtener_cmd(char *ini, char *fin)
{
	size_t n = (size_t)(fin - ini) + 2;
	char *str = malloc(n);
	if(str==NULL)
	{
		perror("Algo ha ido mal en malloc");
		return NULL;
	}
	n--;
	memcpy(str, ini, n);
	str[n] = '\0';

	size_t i;
	for(i=0; i<n; i++){
		if(str[i]=='\0') str[i]=' ';
	}

	return str;
}

int cmd_splano(char **arg)
{

	if((arg[1]==NULL) || (arg[1][0] == '@')) {
		show_help(arg[0]);
		return -1;
	}

	struct proc_t *p;
	int pid, status;
	time_t t;

	int arg_count = 1;
	while (arg[arg_count] != NULL) {
		arg_count++;
	}
	arg_count--;
	char *last_arg = arg[arg_count];

	int prio;
	if(last_arg[0] == '@')
	{
		prio = atoi(last_arg+1);
	}
	else
	{
		errno = 0;
		prio = getpriority(PRIO_PROCESS, 0);
		if((prio==-1) && errno) {
			perror("No se pudo obtener la prioridad del shell");
			return -1;
		}
	}

	t = time(0);
	switch (pid=fork()) {
	case -1:perror("Error en fork");
		return -1;
	
	case 0: printf("hijo\n");
		if(last_arg[0]=='@') {
			if(set_priority(0, prio) != 0) 
			{
				salir_cmd = 1;
				return -1;
			}
			arg[arg_count] = NULL;
		}
		
		if(execvp(arg[1], arg+1)) {
			perror("Error al ejecutar");
		}
		salir_cmd = 1;	
		break;
	
	default:printf("padre\n");
		waitpid(pid, &status, WNOHANG|WUNTRACED|WCONTINUED);

		if((p = list_new(list_proc, sizeof(struct proc_t)) ) == NULL)
		{
			perror("No se pudo añadir a la lista");
			return -1;
		}
		p->pid = pid;
		p->prio = prio;

		char *fin;
		if (last_arg[0] == '@') fin = (last_arg-2);
		else fin = last_arg+strlen(last_arg);

		if(!(p->cmd = obtener_cmd(arg[1], fin)))
		{
			void **p = list_proc->data + (list_proc->n - 1);
			list_delete(list_proc, p);
			return -1;
		}

		p->time = t;
		p->status = PROC_RUN;
		p->sig_exit = 0;
		p->ru = NULL;			 
	}
	
	return 0;	
}
