#include "infoproc.h"
#include <stdio.h>

void print_row_proc(struct proc_t *p)
{
	printf("%d\n", p->pid);
}

void print_list_proc()
{
	int n = list_proc->n;
	int i;
	struct proc_t **p = (struct proc_t **)list_proc->data;
	for(i = 0; i<n; i++)
	{
		
		proc_refresh(p[i]);
		print_row_proc(p[i]);
	}
}

int cmd_infoproc(char **args)
{
	if(args[1]==NULL)
	{
		printf("Uso: %s PID\n", args[0]);
		return -1;
	}


	
	return -1;
}

