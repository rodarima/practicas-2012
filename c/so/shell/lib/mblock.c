#include "mblock.h"

const char *mblock_type_name[] = {"-malloc", "-mmap", "-shared"};
 
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
