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
		printf("%s\n", namelist[i]->d_name);
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
int cmd_list(char **argv)
{
	struct dirent **namelist;
	int n;
	
	char *directorio = argv[1] ? argv[1]:".";

	n = scandir(directorio, &namelist, 0, alphasort);
	
	
	if (n < 0){
		perror("scandir");
		return -1;
	}
	printf("total %d\n", n);
	
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
				imprime_entrada(namelist[indice]->d_name,
								max);
				free(namelist[indice]);
			}
		}
		printf("\n");
	}
	free(namelist);
	return 0;
}
*/
