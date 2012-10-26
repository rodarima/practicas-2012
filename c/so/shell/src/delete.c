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

#include "delete.h"


int cmd_delete(char **arg)
{
	if(arg[1]==NULL){
		printf("Falta un operando\nUso: %s [ARCHIVO]\n", arg[0]);
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

