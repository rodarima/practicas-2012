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
#define COMANDOS_H

#include "pwd.h"
#include "pid.h"
#include "delete.h"
#include "deltree.h"
#include "chdir.h"
#include "list.h"
#include "quit.h"
//Practica 2
#include "priority.h"

struct cmd_t {
	char *name;
	int (*pfunc)(char **);
};

int cmd_pid(char **arg);


struct cmd_t lista_cmd[] = 
{
	//{"ls", cmd_ls},
	{"pwd", cmd_pwd},
	{"pid", cmd_pid},
	{"delete", cmd_delete},
	{"deltree", cmd_deltree},
	{"chdir", cmd_chdir},
	{"list", cmd_list},
	{"quit", cmd_quit},
	{"fin", cmd_quit},
	{"exit", cmd_quit},
	
	//Practica 2
	{"prio", cmd_prio},
	


	// Funciones reales
	{"rm", cmd_delete},
	{"cd", cmd_chdir},
	{"ls", cmd_list},
	
	
	{NULL, NULL}
};

#endif /* COMANDOS_H */
