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

#include "fork.h"

int cmd_fork(char **arg)
{
	int pid;
	int stat;
	
	switch (pid=fork()) {
		
		case -1: perror("Error en fork");
			 return -1;
			 
		case 0: break;				//Es el hijo
		
		default: waitpid(pid, &stat, 0);	//Es el padre
	}
	
	return 0;
}
