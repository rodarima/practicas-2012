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

#include "splano.h"
#include "../lib/proc.h"
#include "../lib/arg_prio.h"
#include "global.h"
#include "help.h"
#include "priority.h"
#include <sys/time.h>
#include <sys/resource.h>
#include <errno.h>

void borrar_proc(void *p)
{
	struct proc_t *proc = (struct proc_t *)p;
	free(proc->cmd);
}

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
	int pid;
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
		if(prio>19) prio = 19;
		else if(prio<-20) prio = -20;
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
	
	case 0: //printf("hijo\n");
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
	
	default://printf("padre\n");
		//waitpid(pid, &status, WNOHANG|WUNTRACED|WCONTINUED);

		/* Excluimos el último argumento si es la prioridad */
		if (last_arg[0] == '@') arg_count--;

		/* Añadimos la longitud de la última palabra */
		char *fin = arg[arg_count]+strlen(arg[arg_count])-1;

		/* Obtenemos la linea de comando desde el principio hasta el
		último carácter de la última palabra */
		char *cmd = obtener_cmd(arg[1], fin);

		/* Si obtener_cmd falla, salimos. */
		if(cmd == NULL) return -1;

		/* Creamos una nueva entrada en la lista */
		if((p = list_new(list_proc, sizeof(struct proc_t), borrar_proc)) == NULL)
		{
			perror("No se pudo añadir a la lista");
			return -1;
		}

		/* Añadimos todos los campos */
		p->pid = pid;
		p->prio = prio;
		p->cmd = cmd;
		p->time = t;
		p->status = PROC_RUN;

		/* Ponemos inicialmente sig_exit y ru a 0 */
		p->sig_exit = 0;
		memset(&(p->ru), 0, sizeof(struct rusage));
	}
	
	return 0;	
}
