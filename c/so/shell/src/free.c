#include "free.h"
#include "mem.h"
#include "../lib/mblock.h"
#include "mem.h"
#include "global.h"
#include "malloc.h"


int cmd_free(char **arg)
{
	if(arg[1]==NULL)
	{
		list_mem_print(MTYPE_MALLOC);
		return 0;
	}

	size_t tam = atol(arg[1]);

	size_t i = 0;
	struct mblock_t *p;
	while((p=(struct mblock_t *)list_get(list_mem, i)))
	{
		if(((p->type) & MTYPE_MALLOC) && (p->size == tam))
		{
			//free_mblock_malloc(p);
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
		printf("No se ha encontrado ningún bloque de %zu bytes\n", tam);
		return -1;
	}

	return 0;
}
