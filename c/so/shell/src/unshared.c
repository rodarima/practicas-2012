#include "unshared.h"
#include "global.h"
#include "mem.h"
#include "../lib/mblock.h"
#include "../lib/list.h"

int cmd_unshared(char **arg)
{
	if (arg[1]==NULL) {
		list_mem_print(MTYPE_SHARED);
		return 0;
	}
	
	size_t sz = (size_t)strtoul(arg[1], NULL, 10);
	int pos = 0;
	struct mblock_t *b;
	
	while ((b=(struct mblock_t *)list_get(list_mem, pos)) != NULL) {
		if ((b->type==MTYPE_SHARED)&&(b->size==sz)) {
			shmdt(b->addr);
			list_delete(list_mem, pos);
			break;
		}else {
			pos++;
		}
	}
	if (b==NULL) {
		printf("No se ha encontrado ningún bloque de %lu bytes\n", sz);
		return -1;
	}
	
	return 0;
}
