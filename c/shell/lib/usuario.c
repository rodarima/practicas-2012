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
