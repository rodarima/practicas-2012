#include "malloc.h"
#include "global.h"
#include "../lib/list.h"
#include "../lib/mblock.h"

void free_mblock(void *pos)
{
	struct mblock_t *element = (struct mblock_t *)pos;
	free(element->addr);
}

int cmp_mblock(void *a, void *b)
{
	struct mblock_t *mbka = (struct mblock_t *)a;
	struct mblock_t *mbkb = (struct mblock_t *)b;

	if(mbka->type < mbkb->type) return -1;
	if(mbka->type > mbkb->type) return 1;
	if(mbka->time < mbkb->time) return -1;
	if(mbka->time > mbkb->time) return 1;
	return 0;
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

	if(list_insert(list_mem, b, free_mblock, cmp_mblock))
	{
		perror("No se ha podido insertar en la lista");
		return -1;
	}

	printf("%p\n", p);
	
	return 0;
}
