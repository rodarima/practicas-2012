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

#include "prog.h"
#include "global.h"
#include "help.h"

int cmd_prog(char **arg)
{
	if(arg[0][0] == '@')
	{
		printf("Uso: PROGRAM [ARGS ...] [@PRIORITY]\n");
		return -1;
	}
	int pid, status;
	int arg_count = 0;
	while (arg[arg_count]!=NULL) {
		arg_count++;
	}
	char *last_arg = arg[arg_count-1];
	
	switch (pid=fork()) {
		
		case -1: perror("Error en fork");
			 return -1;
			 
		case 0:	if(last_arg[0]=='@') {
				setpriority(PRIO_PROCESS, 0, atoi(last_arg+1));
				arg[arg_count-1] = NULL;
			}
			
			if(execvp(arg[0], arg)) {
				perror("Error al ejecutar");
			}
			salir_cmd = 1;	
			break;
			
		default: waitpid(pid, &status, 0);
	}
		
	return 0;
}
