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

#include "global.h"
#include "borraprocesos.h"
#include "../lib/proc.h"
#include <string.h>


int cmd_borraprocesos(char **arg)
{
	char ind;
	int len = PROC_NSTATUS;

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

		list_delete(list_proc, i);
		i--;
	}
	return 0;
}
