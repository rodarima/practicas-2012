#include "deltree.h"

int borrar_archivo(char *ruta)
{
	int r = 0;
		if(remove(ruta)!=0){
						
			char * str = "delete: no se puede borrar «%s»";
			char * err = malloc(strlen(str) - 1 + strlen(ruta));
			if(!err){
				perror("Algo ha fallado en malloc");
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
		printf("Error: no se pueden obtener las entradas del directorio especificado");
		return -1;
	}
	
	int i;
	for(i=0; i<n; i++){
		//directorio? recursividad
		char *dirname = dirlist[i]->d_name;
		char *new_path = concatenar_carpeta(ruta, dirname);
		
		if(!new_path){
			perror("concatenar_carpeta");
			break;
		}
		
		if (is_dir(new_path)) {	  
			if((strcmp(dirname, "..")!=0) &&
			   (strcmp(dirname, ".")!=0)) {
					deltree(new_path);
					//printf("Borrando.. %s\n", new_path);
					borrar_archivo(new_path);
			}
		}else {
			//printf("Borrando.. %s\n", new_path);
			int borrado = borrar_archivo(new_path);
			if (borrado != 0)
				printf("No se ha podido eliminar el archivo %s\n", new_path);
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
		printf("%s: falta un operando\n", arg[0]);
		return -1;
	}
	
	deltree(ruta);
	//printf("Borrando.. %s\n", ruta);
	borrar_archivo(ruta);
	
	return 0;
}
