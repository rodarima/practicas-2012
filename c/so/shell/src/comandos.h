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

#ifndef COMANDOS_H
#define COMANDOS_H 1

#include "pwd.h"
#include "pid.h"
#include "delete.h"
#include "deltree.h"
#include "chdir.h"
#include "list.h"
#include "quit.h"
#include "help.h"
 
//Practica 2
#include "priority.h"
#include "fork.h"
#include "ejecutar.h"
#include "splano.h"
#include "pplano.h"
#include "procesos.h"
#include "borraprocesos.h"
#include "infoproc.h"

struct cmd_t {
	const char *name;
	int (*pfunc)(char **);
	const char *use;
};

int cmd_pid(char **arg);


static struct cmd_t lista_cmd[] = 
{
	//Práctca 1
	{"pwd", 	cmd_pwd,	"pwd"},
	{"pid", 	cmd_pid,	"pid"},
	{"delete", 	cmd_delete,	"delete FILE"},
	{"deltree", 	cmd_deltree,	"deltree DIR"},
	{"chdir", 	cmd_chdir,	"chdir [DIR]"},
	{"list", 	cmd_list,	"list [-l] [-r] [-h] [DIR]"},
	{"quit", 	cmd_quit,	"quit"},
	{"fin", 	cmd_quit,	"fin"},
	{"exit", 	cmd_quit,	"exit"},
	
	//Practica 2
	{"prio", 	cmd_prio,	"prio [PID [PRIORITY]]"},
	{"fork", 	cmd_fork,	"fork"},
	{"ejecutar", 	cmd_ejecutar,	"ejecutar PROGRAM [ARGS ...] [@PRIORITY]"},	
	{"splano", 	cmd_splano,	"splano PROGRAM [ARGS ...] [@PRIORITY]"},
//	{"pplano", 	cmd_pplano,	"pplano PID"},
	{"procesos", 	cmd_procesos,	"procesos [all|term|sig|stop|act]"},
	{"borraprocesos", cmd_borraprocesos, "borraprocesos [all|term|sig|stop|act]"},
	{"infoproc", 	cmd_infoproc, "infoproc PID"},
	
	// Funciones reales
	{"rm", 		cmd_delete,	"rm FILE"},
	{"cd", 		cmd_chdir,	"chdir [DIR]"},
	{"ls", 		cmd_list,	"ls [-l] [-r] [-h] [DIR]"},
	{"help", 	cmd_help,	"help [COMANDO]"},
	
	
	{NULL, NULL, NULL}
};

#endif /* COMANDOS_H */
