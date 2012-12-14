#include "uid.h"

int cmd_uid(char **arg)
{
	uid_t euid;
	
	if (arg[1]==NULL) {
		euid = geteuid();
		struct passwd *pw = getpwuid(euid);
		char *login = pw->pw_name;
		printf("%d %s\n", euid, login);
	}
	return 0;
}
