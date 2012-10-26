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

#include "path.h"

char *obtener_path(){
	char * dir = getcwd(NULL, 0);
	if(!dir){
		perror("Algo ha ido mal en getcwd");
		return NULL;
	}
	char * l = getenv("HOME");
	if (l==NULL) return dir;
	
	int home_len = strlen(l);
	if(strncmp(dir, l, home_len) != 0){
		return dir;
	}
	
	char * path = dir+home_len;
	
	char * path_total = malloc(strlen(path) + 2);
	if(!path_total){
		perror("Algo ha ido mal en malloc");
		return dir;
	}
	path_total[0] = '~';
	strcpy(&path_total[1], path);
	free(dir);
	
	return path_total;
}
