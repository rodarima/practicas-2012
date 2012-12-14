#include "rmkey.h"
#include "help.h"

int cmd_rmkey(char **arg)
{
	if (arg[1]==NULL) {
		show_help(arg[0]);
		return -1;
	}
	
	int shmid;
	key_t key = (key_t)strtoul(arg[1], NULL, 10);
	if (key==IPC_PRIVATE) {
		printf("Error: clave no válida\n");
		return -1;
	}
	
	if ((shmid=shmget(key, 0, 0666)) == -1) {
		perror("shmget");
		return -1;
	}
	
	if (shmctl(shmid, IPC_RMID, NULL)==-1) {
		perror("shmctl");
		return -1;
	}
	return 0;
}
