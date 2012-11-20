#ifndef PROCESOS_H
#define PROCESOS_H

#include <time.h>
#include <sys/resource.h>

struct proc_t 
{	
	int pid;		//ID de proceso (PID)
	int prio;		//Prioridad
	char *cmd;		//Comando
	time_t time;		//Instante de inicio
	int status;		//Estado
	struct rusage ru;	//Uso de recursos
};

#endif
