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

#include "pid.h"

int cmd_pid(char **arg)
{
	printf("El PID del proceso padre es %d, el actual %d.\n", 
								getppid(), 
								getpid());
	return 0;
}

