#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int cmd_pwd(char **arg)
{
	char * dir = getcwd(NULL, 0);
	if(!dir){
		perror("Algo ha ido mal en getcwd");
		return -1;
	}
	printf("%s\n", dir);
	free(dir);
	return 0;
}


