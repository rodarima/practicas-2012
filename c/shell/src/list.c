#include "list.h"

int listar(char *directorio){
	struct dirent **namelist;
	int n;
	
	n = scandir(directorio, &namelist, 0, alphasort);
	
	if (n < 0){
		perror("list");
		return -1;
	}
	
	int i = 0;
	for(i=0; i<n; i++){
		if(namelist[i]->d_name[0]!='.')
			printf(" %s\n", namelist[i]->d_name);
		free(namelist[i]);
	}
	free(namelist);
	return 0;
}

int cmd_list(char **argv)
{
	char *directorio = argv[1] ? argv[1]:".";

	return listar(directorio);
}

/*
//Devuelve la verdadera longitud de una cadena, incluyendo acentos y demás
int strlen_utf8(char *s) {
	int i = 0, j = 0;
	while (s[i]) {
		if ((s[i] & 0xc0) != 0x80) j++;
		i++;
	}
	return j;
}

void imprime_entrada(char* entrada, int ancho){
	int len = strlen_utf8(entrada)+2;
	
	printf("%s  ", entrada);
	while(len++ < ancho) printf(" ");
}

int ancho_terminal()
{
	struct winsize w;
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);

	return w.ws_col;
}

int imprime_directorio(char * dir, int ancho){
	int len = strlen_utf8(dir);
	
	printf("%s", dir);
	
	struct stat statbuf;
	
	if(stat(dir, &statbuf) == -1){
		perror("stat");
		return -1;
	}
        if(S_ISDIR(statbuf.st_mode)){
		printf("/");
		len++;
	}
	while(len++ < ancho) printf(" ");
	return 0;

}

struct dirent ** ocultar_entradas(struct dirent ***e, int n)
{
	struct dirent ** entry1 = *e;
	
	int num_puntos = 0;
	int i;
	
	for(i=0; i<n; i++){
		if(entry1[i]->d_name[0] == '.') num_puntos++;
	}
	struct dirent **entry2 = malloc(num_puntos*sizeof(struct dirent *));
	
	for(i=0; i<n; i++){
		if(entry1[i]->d_name[0] == '.') {
			entry2[i]=entry1[1];
		}
	}
	
	return entry2;
}

int cmd_list(char **argv)
{
	struct dirent **namelist;
	int n;
	
	char *directorio = argv[1] ? argv[1]:".";

	n = scandir(directorio, &namelist, 0, alphasort);
	
	if (n < 0){
		perror("list");
		return -1;
	}
	
	int max = 0;
	int i = 0;
	for(i=0; i<n; i++){
		if(max < (strlen(namelist[i]->d_name)+2)){
			max = strlen(namelist[i]->d_name) + 2;
		}
	}
	int ancho = ancho_terminal();
	int col = ancho/max;
	int fil = (n+col-1)/col;
	int j=0;
	for(i=0; i<fil; i++){
		for(j=0; j<col; j++){
			int indice = (col*i)+j;
			if(indice<n) {
				imprime_directorio(namelist[indice]->d_name, max);
				free(namelist[indice]);
			}
		}
		printf("\n");
	}
	free(namelist);
	return 0;
}

*/
