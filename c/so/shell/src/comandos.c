#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include "comandos.h"

int main(){
	//cmd_pid(0, NULL);
	commands[1].pfunc(NULL);
	return 0;
}
