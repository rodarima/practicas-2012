#ifndef COMANDOS_H
#define COMANDOS_H

#include "pwd.h"
#include "pid.h"
#include "delete.h"
#include "chdir.h"
#include "list.h"

struct cmd_t {
	char * name;
	int (*pfunc)(char **);
};

int cmd_pid(char **arg);


struct cmd_t lista_cmd[] = 
{
	//{"ls", cmd_ls},
	{"pwd", cmd_pwd},
	{"pid", cmd_pid},
	{"delete", cmd_delete},
	{"chdir", cmd_chdir},
	{"list", cmd_list},
	
	// Funciones reales
	
	{"rm", cmd_delete},
	{"cd", cmd_chdir},
	{"ls", cmd_list},
	
	
	{NULL, NULL}
};

#endif /* COMANDOS_H */
