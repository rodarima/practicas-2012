#include "uid.h"
#include "help.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <pwd.h>

int cmd_uid(char **arg)
{
	uid_t uid, euid;
	struct passwd *pw;
	
	if (arg[1]==NULL) {
		char *login, *info, *elogin, *einfo;
		char *desc = "desconocido";
		uid = getuid();
		euid = geteuid();
		if((pw = getpwuid(uid))) {
			login = pw->pw_name;
			info = pw->pw_gecos;
		} else {
			login = desc;
			info = desc;
		}			
		if ((pw=getpwuid(euid))) {
			elogin = pw->pw_name;
			einfo = pw->pw_gecos;
		} else {
			elogin = desc;
			einfo = desc;		
		}
		printf("UID         LOGIN                  NAME E_UID     E_LOGIN                E_NAME\n");		
		printf("%-6d %10s %21s %-6d %10s %21s\n", uid, login, info, euid, elogin, einfo);
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
		if (setuid(pw->pw_uid)!=0) {
			perror("setuid");
			return -1;
		}
		return 0;
	}
	
	uid = (uid_t)atoi(arg[1]);
	if (setuid(uid)!=0) {
		perror("setuid");
		return -1;
	}	
	
	return 0;
}
