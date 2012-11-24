#include "arg_prio.h"
#include "stdio.h"

char *get_arg_prio(char **args)
{
	int i = 1;
	while(args[i])
	{
		i++;
	}
	if(i == 1) return NULL;
	i--;

	char *p = args[i];

	if(p[0] != '@')
	{
		return NULL;
	}
	args[i] = NULL;

	return p+1;
}