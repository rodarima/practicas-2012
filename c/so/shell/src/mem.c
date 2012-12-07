#include "mem.h"
#include "global.h"
#include "mblock.h"
#include "../lib/list.h"

/*
 * COSAS PENDIENTES
 * - Array global de tipos de asignación de memoria
 * - Impresión correcta de los elementos de la lista
 * - cmp_mblock en mblock.h?
 */

void list_mem_print(char mask);
{
	int pos = 0;
	struct mblock_t *m;
	
	if (mask&MTYPE_MALLOC) {
		printf("Espacios reservados con malloc:\n");
		printf("\nDIRECCIÓN             TAMAÑO  INSTANTE ASIG\n");
		while (pos<list_mem->n) {
			m = list_get(list_mem, pos);
			if (!(m->type&MTYPE_MALLOC)) break;
			printf("%21p %10d %21s",
				m->addr,
				m->size,
			);
			pos++;
		}
	}
	if (mask&MTYPE_MMAP) {
		printf("Espacios reservados con mmap:\n");
		printf("\nDIRECCIÓN             TAMAÑO         INSTANTE ASIG    FD NOMBRE\n");
		while (pos<list_mem->n) {
			m = list_get(list_mem, pos);
			if (!(m->type&MTYPE_MMAP)) break;
			printf("");
			pos++;
		}		
	}
	if (mask&MTYPE_SHARED) {
		printf("Espacios reservados con shared:\n");
		printf("\nDIRECCIÓN             TAMAÑO         INSTANTE ASIG    ID  KEY\n");
		while (pos<list_mem->n) {
			m = list_get(list_mem, pos);
			if (!(m->type&MTYPE_SHARED)) break;
			printf("");
			pos++;
		}		
	}
}

int cmd_mem(char **arg)
{
	if (arg[1]==NULL) {
		list_mem_print(MTYPE_MALLOC | MTYPE_MMAP | MTYPE_SHARED);
		return 0;
	}
	char ind;
	for (ind=0x01; ind&(MTYPE_MALLOC | MTYPE_MMAP | MTYPE_SHARED); ind*2) {
		if (strcmp(arg[1], mblock_type_name[(int)log2((double)ind)]) == 0) {
			break;
		}
		list_mem_print(i);
	}
	return 0;
}
