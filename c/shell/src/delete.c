#include "delete.h"

int cmd_delete(char **arg)
{
	if(arg[1]==NULL){
		printf("No se indicó el archivo a borrar.\n");
		return 0;
	}
	int i = 1, r = 0;;
	while(arg[i]){
		if(unlink(arg[i])!=0){
			printf("delete: no se puede borrar «%s»: %s\n", 
							arg[i], 
							sys_errlist[errno]);
			r=-1;
		}
		i++;
	}
	return r;
}

