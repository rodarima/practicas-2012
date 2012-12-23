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
