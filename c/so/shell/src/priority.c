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
#include <sys/types.h>
#include <stdlib.h>
#include <errno.h>

#include "priority.h"

#define NOPID	0

char *priorities[] = { "Muy alta", "Alta", "Normal", "Baja", "Muy baja" };

#define GETPRIO(p)  priorities[((p+20)/8)%5] 

int get_priority(pid_t pid, int *p)
{
	errno = 0;
	int prio = getpriority(PRIO_PROCESS, pid);
	if((prio==-1) && errno) {
		perror("No se pudo obtener la prioridad");
		return -1;
	}
	*p=prio;
	return 0;
}

int show_priority(pid_t pid)
{
	errno = 0;
	int prio = getpriority(PRIO_PROCESS, pid);
	if((prio==-1) && errno) {
		perror("No se pudo obtener la prioridad");
		return -1;
	}
	if(pid==NOPID)
	{
		printf("Prioridad del shell: %d (%s)\n", prio, GETPRIO(prio));
	}
	else
	{
		printf("Prioridad del proceso %d: %d (%s)\n", pid, prio, GETPRIO(prio));
	}
	return 0;
}

int set_priority(pid_t pid, int prio)
{
	if(setpriority(PRIO_PROCESS, pid, prio)) {
		perror("No se pudo establecer la prioridad");
		return -1;
	}
	//printf("Prioridad del proceso %d: %d\n", pid, prio);
	return 0;
}

int cmd_prio(char **arg)
{
	if(arg[1]==NULL){
		show_priority(NOPID);
	}else if(arg[2]==NULL){
		pid_t pid = atoi(arg[1]);
		show_priority(pid);

	}else if(arg[3]==NULL){
		pid_t pid = atoi(arg[1]);
		int prio = atoi(arg[2]);
		set_priority(pid, prio);
	}
		
		
	return 0;
}

