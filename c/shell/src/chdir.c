#include "chdir.h"

int cmd_chdir(char **arg)
{
	
	if(arg[1] == NULL)
		return -1;
	
	if(chdir(arg[1]) != 0){
		perror("No se pudo cambiar el directorio");
		return -1;
	}
		
		
	return 0;
}

