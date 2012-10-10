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
			
			char * str = "delete: no se puede borrar «%s»";
			char * err = malloc(strlen(str) - 1 + strlen(arg[i]));
			if(!err){
				perror("Algo ha fallado en malloc");
				continue;
			}
			sprintf(err, str, arg[i]);
			perror(err);
			free(err);
			r=-1;
		}
		i++;
	}
	return r;
}

