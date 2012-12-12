#include "malloc.h"
#include "global.h"
#include "mem.h"
#include "../lib/list.h"
#include "../lib/mblock.h"

void free_mblock_malloc(void *pos)
{
	struct mblock_t *element = (struct mblock_t *)pos;
	free(element->addr);
}

int cmd_malloc(char **arg)
{
	if(arg[1]==NULL) {
		list_mem_print(MTYPE_MALLOC);
		return 0;
	}
	
	size_t size = atol(arg[1]);
	time_t t = time(0);
	void *p = malloc(size);	
	if(p==NULL) {
		perror("No se pudo reservar el espacio solicitado");
		return -1;
	}
	
	//struct mblock_t *b = list_new(list_mem, sizeof(struct mblock_t), free_mblock);
	struct mblock_t *b = malloc(sizeof(struct mblock_t));
	if(b==NULL) {
		perror("malloc ha fallado");
		return -1;
	}

	b->addr = p;
	b->size = size;
	b->time = t;
	b->type = MTYPE_MALLOC;

	if(list_insert(list_mem, b, free_mblock_malloc, cmp_mblock))
	{
		perror("No se ha podido insertar en la lista");
		return -1;
	}

	printf("%p\n", p);
	
	return 0;
}
