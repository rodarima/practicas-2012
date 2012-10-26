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

#include "usuario.h"


char *nombre_login()
{
	char * l = getenv("USER");
	return l ? l : USUARIO_ALTERNATIVO;
}

char *nombre_pc(){
	char buffer[1024];
	
	if(gethostname(buffer, 1023)!=0){
		perror("Algo ha fallado en gethostname");
		return NULL;
	}
	
	buffer[1023]='\0';
	int len = strlen(buffer);
	
	char *pc = malloc(len*sizeof(char)+1);
	if(!pc){
		perror("Algo ha fallado en malloc");
		return NULL;
	}
	strcpy(pc, buffer);
	return pc;
}
