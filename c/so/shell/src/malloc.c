#include "malloc.h"
#include "global.h"
#include "../lib/list.h"
#include "../lib/mblock.h"

void free_mblock(void *pos)
{
	struct mblock_t *element = (struct mblock_t *)pos;
	free(element->addr);
}

int cmd_malloc(char **arg)
{
	if(arg[1]==NULL) {
		//imprimir lista de mallocs
		return 0;
	}
	
	int size = atoi(arg[1]);
	time_t t = time(0);
	void *p = malloc(size);	
	if(p==NULL) {
		perror("No se pudo reservar el espacio solicitado");
		return -1;
	}
	
	struct mblock_t *b = list_new(list_mem, sizeof(struct mblock_t), free_mblock);
	if(b==NULL) {
		perror("No se pudo insertar la nueva entrada en la lista");
		return -1;
	}
	
	printf("%p\n", p);
	b->addr = p;
	b->size = size;
	b->time = t;
	b->type = MTYPE_MALLOC;
	
	return 0;
}
