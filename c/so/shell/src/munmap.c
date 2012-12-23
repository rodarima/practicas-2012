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

#include "munmap.h"
#include "../lib/mblock.h"
#include "../lib/list.h"
#include <sys/mman.h>
#include <stdio.h>
#include "mem.h"
#include "global.h"
#include "mmap.h"

int cmd_munmap(char ** arg)
{
	if(arg[1] == NULL)
	{
		list_mem_print(MTYPE_MMAP);
		return 0;
	}
	char *f = arg[1];
	size_t i = 0;
	struct mblock_t *p = NULL;
	while(i < list_mem->n)
	{
		p = (struct mblock_t *) list_get(list_mem, i);
		if((p->type == MTYPE_MMAP) &&
		   (strcmp(f, p->name)==0))
		{
			/* si encontramos el elemento */

			if(munmap(p->addr, p->size) != 0)
			{
				perror("munmap ha fallado");
				return -1;
			}

			/* borramos solo la 1 ocurrencia */
			//free_mmap(p);
			list_delete(list_mem, i);
			return 0;
		}

		i++;
	}

	printf("No se ha encontrado %s\n", f);
	return -1;
}
