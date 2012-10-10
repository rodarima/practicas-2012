#include "list.h"

int cmd_list(char **argv)
{
	struct dirent **namelist;
	int n;
	
	char *directorio = argv[1] ? argv[1]:".";

	n = scandir(directorio, &namelist, 0, alphasort);
	if (n < 0)
		perror("scandir");
	else {
		while(n--) {
			printf("%s\n", namelist[n]->d_name);
			free(namelist[n]);
		}
		free(namelist);
	}
	return 0;
}

