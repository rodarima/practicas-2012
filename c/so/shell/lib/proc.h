#ifndef PROCESOS_H
#define PROCESOS_H

#include <time.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <sys/types.h>
#include <sys/wait.h>

struct proc_t 
{	
	int pid;		//ID de proceso (PID)
	int prio;		//Prioridad
	char *cmd;		//Comando
	time_t time;		//Instante de inicio
	char status;		//Estado
	int sig;		//Señal
	struct rusage *ru;	//Uso de recursos
};

/*
FLAGS EN STATUS

status = RRRRRREE

R = Reservado para el futuro
E = Estado actual

*/
#define PROC_BITS	2
#define PROC_RUN	0x00
#define PROC_TERM	0x01
#define PROC_SIG	0x02
#define PROC_STOP	0x03

#define SETPROCSTATUS(old_status, new_st) do { (old_status)=((old_status)&(0xff<<PROC_BITS))|((new_st)&(0xff>>(8-PROC_BITS))); } while(0);


void proc_refresh(struct proc_t *p);

#endif
