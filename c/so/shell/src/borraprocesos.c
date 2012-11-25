#include "global.h"
#include "borraprocesos.h"
#include "../lib/proc.h"
#include <string.h>

void free_cmd_proc(struct proc_t *p)
{
	if(p->cmd) free(p->cmd);
	return;
}

void free_cmd_proc_list()
{
	int i;
	int n = list_proc->n;
	for(i=0; i<n; i++)
	{
		free_cmd_proc(list_proc->data[i]);
	}
}

int cmd_borraprocesos(char **arg)
{
	char ind;
	int len = sizeof(proc_name_status) / sizeof(char *);

	if(arg[1] != NULL)
	{

		for(ind = 0x00; ind<len; ind++)
		{
			if(strcmp(proc_name_status[(int)ind], arg[1]) == 0){
				break;
			}
		}

	}
	else ind = len;
	int i;
	struct proc_t **proc = (struct proc_t **)list_proc->data;
	struct proc_t *p;
	for(i=0; i<list_proc->n; i++)
	{

		p = proc[i];
		proc_refresh(p);

		if((ind<len) && (!ISPROCSTATUS(p->status, ind))) continue;

		free_cmd_proc(p);
		list_delete(list_proc, list_proc->data+i);
		i--;
	}
}