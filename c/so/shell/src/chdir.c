#include "chdir.h"

int cmd_chdir(char **arg)
{
	char *dir = arg[1];
	
	// Si solo se pone chdir ir al directorio home/usuario
	if(dir == NULL){
		return cmd_pwd(arg);
	}
	
	
	if(chdir(dir) != 0){
		perror("No se pudo cambiar el directorio");
		return -1;
	}
		
		
	return 0;
}

