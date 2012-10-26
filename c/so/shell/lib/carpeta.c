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

#include "carpeta.h"


char *concatenar_carpeta(char *path, char *path2)
{
	int l_path = strlen(path);
	char *fin;
	if((l_path>=0) && (path[l_path-1]=='/')){
		fin = malloc(l_path + strlen(path2) + 1);
		if(!fin) return NULL;
		strcpy(fin, path);
		strcat(fin, path2);
	}else{
		fin = malloc(l_path + strlen(path2) + 2);
		if(!fin) return NULL;
		strcpy(fin, path);
		strcat(fin, "/");
		strcat(fin, path2);
	}
	return fin;
}


int is_dir(char *dir)
{
	struct stat sb;

	if (lstat(dir, &sb) == -1) {
		perror(dir);
		return 0;
	}
	return S_ISDIR(sb.st_mode);

}
