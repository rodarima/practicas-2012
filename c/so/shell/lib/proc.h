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

#ifndef PROC_H
#define PROC_H

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
	int sig_exit;		//Señal o valor devuelto
	struct rusage ru;	//Uso de recursos
};

/*
FLAGS EN STATUS

status = RRRRRREE

R = Reservado para el futuro
E = Estado actual

*/
#define PROC_RUN	0x00
#define PROC_TERM	0x01
#define PROC_SIG	0x02
#define PROC_STOP	0x03

#define PROC_NSTATUS	4

#define PROC_BITS	2
#define PROC_MASK	(0xff>>(8-PROC_BITS))
#define PROC_UMASK	(0xff<<(PROC_BITS))

extern const char *proc_name_status[];


#define SETPROCSTATUS(old, st) do {\
(old)=(((old)&PROC_UMASK)|((st)&PROC_MASK));} while(0);
#define ISPROCSTATUS(a, b) (((a)&PROC_MASK)==((b)&PROC_MASK))?1:0
#define GETPROCSTATUS( status ) proc_name_status[((status)&PROC_MASK)]
//#define CHECKPROCSTATUS(status, mask) 	((status)<<(8-PROC_BITS))&((mask)<<(8-PROC_BITS))

void proc_refresh(struct proc_t *p);


#endif
