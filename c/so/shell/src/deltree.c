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

#include "deltree.h"

int borrar_archivo(char *ruta)
{
	int r = 0;
	if(remove(ruta)!=0){
					
		char * str = "delete: no se puede borrar «%s»";
		char * err = malloc(strlen(str) - 1 + strlen(ruta));
		if(!err){
			perror("Algo ha fallado en malloc");
			return -1;
		}
		sprintf(err, str, ruta);
		perror(err);
		free(err);
		r = -1;
	}
	return r;		
}

int deltree(char *ruta)
{
	struct dirent **dirlist;
	int n = scandir(ruta, &dirlist, NULL, alphasort);
	if (n < 0) {
		perror("scandir");
		return -1;
	}
	
	int i;
	for(i=0; i<n; i++){
		//directorio? recursividad
		char *dirname = dirlist[i]->d_name;
		char *new_path = concatenar_carpeta(ruta, dirname);
		
		if(!new_path){
			perror("Concatenar_carpeta");
			break;
		}
		
		if(is_dir(new_path))
		{	  
			if((strcmp(dirname, "..")!=0) &&
			   (strcmp(dirname, ".")!=0)) 
			{
				deltree(new_path);
				//printf("Borrando.. %s\n", new_path);
				borrar_archivo(new_path);
			}
		}
		else
		{
			//printf("Borrando.. %s\n", new_path);
			int borrado = borrar_archivo(new_path);
			if (borrado != 0)
				printf("Imposible borrar:%s\n", new_path);
		}	
		free(new_path);
		free(dirlist[i]);
	}
	
	free(dirlist);
		
	return 0;
}

int cmd_deltree(char **arg)
{	
	char *ruta = arg[1];
	if (!ruta) {
		printf("Falta un operando\nUso: %s [ARCHIVO]\n", arg[0]);
		return -1;
	}
	
	deltree(ruta);
	//printf("Borrando.. %s\n", ruta);
	borrar_archivo(ruta);
	
	return 0;
}
