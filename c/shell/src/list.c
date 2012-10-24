#include "list.h"

int ocultar(const struct dirent *dir);
int is_dir(char *dir);
int listar_l(char* ruta, struct dirent *dir);
int listar_r(char *ruta, struct dirent **dirlist, int n);
int listar_h(char *directorio);
char * concatenar_carpeta(char *path, char *path2);

char modo;

int ocultar(const struct dirent *dir)
{
	if(!(modo & MODO_H) && (dir->d_name[0]=='.')) return 0;
	return 1;
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


/*
 *  Importado de coreutils
 * 
 */
char ftypelet (mode_t bits)
{
  /* These are the most common, so test for them first.  */
  if (S_ISREG (bits))
    return '-';
  if (S_ISDIR (bits))
    return 'd';

  /* Other letters standardized by POSIX 1003.1-2004.  */
  if (S_ISBLK (bits))
    return 'b';
  if (S_ISCHR (bits))
    return 'c';
  if (S_ISLNK (bits))
    return 'l';
  if (S_ISFIFO (bits))
    return 'p';

  /* Other file types (though not letters) standardized by POSIX.  */
  if (S_ISSOCK (bits))
    return 's';

  /* Nonstandard file types.  
  if (S_ISCTG (bits))
    return 'C';
  if (S_ISDOOR (bits))
    return 'D';
  if (S_ISMPB (bits) || S_ISMPC (bits))
    return 'm';
  if (S_ISNWK (bits))
    return 'n';
  if (S_ISPORT (bits))
    return 'P';
  if (S_ISWHT (bits))
    return 'w';
  */

  return '?';
}

/* Like filemodestring, but rely only on MODE.  */

void strmode (mode_t mode, char *str)
{
  str[0] = ftypelet (mode);
  str[1] = mode & S_IRUSR ? 'r' : '-';
  str[2] = mode & S_IWUSR ? 'w' : '-';
  str[3] = (mode & S_ISUID
            ? (mode & S_IXUSR ? 's' : 'S')
            : (mode & S_IXUSR ? 'x' : '-'));
  str[4] = mode & S_IRGRP ? 'r' : '-';
  str[5] = mode & S_IWGRP ? 'w' : '-';
  str[6] = (mode & S_ISGID
            ? (mode & S_IXGRP ? 's' : 'S')
            : (mode & S_IXGRP ? 'x' : '-'));
  str[7] = mode & S_IROTH ? 'r' : '-';
  str[8] = mode & S_IWOTH ? 'w' : '-';
  str[9] = (mode & S_ISVTX
            ? (mode & S_IXOTH ? 't' : 'T')
            : (mode & S_IXOTH ? 'x' : '-'));
  str[10] = ' ';
  str[11] = '\0';
}


int listar_l(char *ruta_vieja, struct dirent *dir)
{
	if(modo&MODO_L){
		struct stat info;
		int check_stat;
		
		char *ruta = concatenar_carpeta(ruta_vieja, dir->d_name);
		if(!ruta){
			perror("concatenar carpeta");
			return -1;
		}
		check_stat = lstat(ruta, &info);		
		free(ruta);
		if (!check_stat) {
			printf(" %7ld ", (long)info.st_ino); 		//I-nodo
			
			//Obtener permisos juas juas
			char buf[12];
			strmode(info.st_mode, buf);
			printf("%s", buf); 				//Permisos
			printf("%3ld ", (long)info.st_nlink); 		//Links
			
			struct passwd *user = getpwuid(info.st_uid);
			if (user){
				printf("%s ", user->pw_name); 		//Propietario (usuario)
			}
			else{
				printf("?? ");
			}
			
			struct group *gr = getgrgid(info.st_uid);
			if (gr){
				printf("%s ", gr->gr_name); 		//Propietario (grupo)
			}
			else{
				printf("?? ");
			}
			
			/*
			struct group gr;
			struct group *gr_p;
			char bufgr[500];
			int errgr = getgrgid_r(info.st_uid, 
				&gr,
				bufgr, 
				500, 
				&gr_p);
			if (!errgr){
				printf("%9s ", gr.gr_name);		//Propietario (grupo)
			}
			else{
				printf("?? ");
			}*/
				
			printf("%9lld  ", (long long)info.st_size); 	//Tamaño (bytes)
			
			char time_string[50];
			struct tm *tm_tiempo = localtime(&info.st_mtime);
			strftime (time_string, sizeof(time_string), "%d %b %Y %H:%M", tm_tiempo);
			printf("%s ", time_string); 			//Fecha de última modificación
			
			printf("%s\n", dir->d_name); 			//Nombre
		}else {
			printf("Error: stat falló");
		}
					
	}else{
		printf(" %s\n", dir->d_name);
	}
	return 0;
}

char * concatenar_carpeta(char *path, char *path2)
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

int listar_r(char *ruta, struct dirent **dirlist, int n)
{
	int i;
	for(i=0; i<n; i++){
		listar_l(ruta, dirlist[i]);
	}
	printf("\n");
	for(i=0; i<n; i++){
		//directorio? recursividad
		char *dirname = dirlist[i]->d_name;
		char *new_path = concatenar_carpeta(ruta, dirname);
		
		if(!new_path){
			perror("concatenar_carpeta");
			break;
		}
		if((modo & MODO_R) && (is_dir(new_path))){
			if((strcmp(dirname, ".")!=0) && 
			   (strcmp(dirname, "..")!=0)){
			   
				listar_h(new_path);
			}
		}
		free(new_path);
		free(dirlist[i]);
	}
	return 0;
}

int listar_h(char *directorio)
{
	printf("%s:\n", directorio);
	struct dirent **namelist;
	int n;
	n = scandir(directorio, &namelist, ocultar, alphasort);
	if (n < 0){
		perror("scandir");
		return -1;
	}
	else {
		if(modo & MODO_L) printf("total: %d archivo(s)\n", n);
		listar_r(directorio, namelist, n);
		free(namelist);
	}
	return 0;
}


int cmd_list(char **argv)
{
	
	int argc = 0;
	modo = 0;
	while(argv[argc]) argc++;
	
	/* RESETEAR A CERO!! */
	optind = 0;
	
	int opt;
	while ((opt = getopt(argc, argv, "lrh")) != -1) {
		switch (opt) {
		case 'l':
			modo|=MODO_L;
			break;
		case 'r':
			modo|=MODO_R;
			break;
		case 'h':
			modo|=MODO_H;
			break;
		default: /* '?' */
			fprintf(stderr, "Uso: %s [-l] [-r] [-h] [dir]\n",
			argv[0]);
			return -1;
		}
	}
	//printf("El modo es %d\n", modo);
	
	
	char *dir;
	//si no se especifica el directorio
	if (optind >= argc) {
		dir = ".";
	}else{
		dir = argv[optind];
	}
	
	//printf("Listar: %s\n", dir);
	listar_h(dir);

	return 0;
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
