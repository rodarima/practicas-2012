#include "procesos.h"
#include "global.h"
#include "proc.h"

int cmd_procesos(char **arg)
{
	char *valid_args[] = {"act", "term", "sig", "stop"};
	char mask = 0x00;
	
	if(arg[2]!=NULL) {
		//show_help(arg[0]);
		return -1;
	}
	
	if((arg[1]=NULL)||(strcmp(arg[1], "all"))) {
		
	}else {
		
	}
	
}
