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
#include <sys/time.h>
#include <sys/resource.h>
#include "priority.h"

int show_priority(){
	int prio = getpriority(PRIO_PROCESS, 0);
	if(prio<0) {
		perror("No se pudo obtener la prioridad.");
		return -1;
	}
	printf("Prioridad del shell: %d\n", prio);
	return 0;
}

int cmd_prio(char **arg)
{
	if(arg[1]==NULL){
		show_priority();
	}
		
		
	return 0;
}

