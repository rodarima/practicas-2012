#ifndef COMANDOS_H
#define COMANDOS_H

#include "pwd.h"
#include "pid.h"
#include "delete.h"

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
	{NULL, NULL}
};

#endif /* COMANDOS_H */
