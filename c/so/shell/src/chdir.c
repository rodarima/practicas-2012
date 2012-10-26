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

#include "chdir.h"

int cmd_chdir(char **arg)
{
	char *dir = arg[1];
	
	// Si solo se pone chdir mostrar el directorio actual
	if(dir == NULL){
		return cmd_pwd(arg);
	}
	
	
	if(chdir(dir) != 0){
		perror("No se pudo cambiar el directorio");
		return -1;
	}
		
		
	return 0;
}

