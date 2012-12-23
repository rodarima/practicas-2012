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

#include "uid.h"
#include "help.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <pwd.h>

/* Obtiene el nombre hasta la primera coma de la descripcion */
char *get_name_gecos(char *desc)
{
	size_t l = strlen(desc);
	size_t i;
	for(i=0; i<l; i++)
	{
		if(desc[i]==',') break;		
	}
	/* i ahora contiene la posicion de la primera coma */
	/* Necesitamos almacenar i caracteres y el fin de linea */
	char *name = malloc(i+1);
	
	if(!name)
	{
		//perror("malloc");
		return desc;
	}

	strncpy(name, desc, i);
	name[i]='\0';

	return name;
}

int cmd_uid(char **arg)
{
	uid_t uid, euid;
	struct passwd *pw, *epw;

	if (arg[1]==NULL) {
		char *login, *info, *elogin, *einfo;
		char *desc = "desconocido";

		uid = getuid();
		euid = geteuid();
		if((pw = getpwuid(uid))) {
			login = strdup(pw->pw_name);
			if(!login) login = desc;
			info = get_name_gecos(pw->pw_gecos);
		} else {
			login = desc;
			info = desc;
		}			
		if ((epw=getpwuid(euid))) {
			elogin = strdup(epw->pw_name);
			if(!elogin) elogin = desc;
			einfo = get_name_gecos(epw->pw_gecos);
		} else {
			elogin = desc;
			einfo = desc;
		}
		printf("UID         LOGIN                  NAME E_UID     E_LOGIN                E_NAME\n");		
		printf("%-6d %10s %21s %-6d %10s %21s\n", uid, login, info, euid, elogin, einfo);
		if(info && (info!=desc)) free(info);
		if(login && (login!=desc)) free(login);
		if(einfo && (einfo!=desc)) free(einfo);
		if(elogin && (elogin!=desc)) free(elogin);

		return 0;

	}
	
	if (strcmp(arg[1], "-l")==0) {
		if (arg[2]==NULL) {
			show_help(arg[0]);
			return -1;
		}
		if ((pw=getpwnam(arg[2]))==NULL) {
			perror("getpwnam");
			return -1;
		}
		if (seteuid(pw->pw_uid)!=0) {
			perror("setuid");
			return -1;
		}
		return 0;
	}
	
	uid = (uid_t)atoi(arg[1]);
	if (seteuid(uid)!=0) {
		perror("setuid");
		return -1;
	}	
	
	return 0;
}
