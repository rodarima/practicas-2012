#include "free.h"
#include "../lib/mblock.h"
#include "mem.h"
#include "global.h"


int cmd_free(char **arg)
{
	if(arg[1]==NULL)
	{
		//mem_show(MTYPE_MALOC);
		return 0;
	}

	size_t tam = atol(arg[1]);

	size_t i = 0;
	struct mblock_t *p;
	while((p=(struct mblock_t *)list_get(list_mem, i)))
	{
		if((p->type) & MTYPE_MALLOC)
		{
			list_delete(list_mem, i);
			break;
		}
		else
		{
			i++;
		}
	}
	if(!p)
	{
		printf("No se ha encontrado ningún bloque de %lu bytes\n", tam);
		return -1;
	}

	return 0;
}
