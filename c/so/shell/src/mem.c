#include "mem.h"
#include "global.h"
#include "../lib/mblock.h"
#include "../lib/list.h"

/*
 * COSAS PENDIENTES
 * - Impresión correcta de los elementos de la lista
 */
void time_to_str(time_t t, char *buffer, size_t size)
{
	struct tm *tm_tiempo;
	
	tm_tiempo = localtime(&t);
	strftime (buffer, size, "%d %b %Y %H:%M:%S", tm_tiempo);
}

void list_mem_print(char mask)
{
	int pos = 0;
	struct mblock_t *m;
	char time_str[50];
	
	if (mask&MTYPE_MALLOC) {
		printf("\nEspacios reservados con malloc:\n");
		printf("DIRECCIÓN                   TAMAÑO INSTANTE\n");
		while (pos<list_mem->n) {
			m = list_get(list_mem, pos);
			if (!(m->type&MTYPE_MALLOC)) break;
			time_to_str(m->time, time_str, sizeof(time_str));
			printf("0x%016lx %15lu %20s\n",
				(unsigned long)m->addr,
				m->size,
				time_str
			);
			pos++;
		}
	}
	if (mask&MTYPE_MMAP) {
		printf("\nEspacios reservados con mmap:\n");
		printf("DIRECCIÓN                   TAMAÑO             INSTANTE FD NOMBRE\n");
		while (pos<list_mem->n) {
			m = list_get(list_mem, pos);
			if (!(m->type&MTYPE_MMAP)) break;
			time_to_str(m->time, time_str, sizeof(time_str));
			printf("0x%016lx %15lu %20s %5d %20s\n",
				(unsigned long)m->addr,
				m->size,
				time_str,
				m->fd,
				m->name
			);
			pos++;
		}		
	}
	if (mask&MTYPE_SHARED) {
		printf("\nEspacios reservados con shared:\n");
		printf("DIRECCIÓN                   TAMAÑO             INSTANTE ID  KEY\n");
		while (pos<list_mem->n) {
			m = list_get(list_mem, pos);
			if (!(m->type&MTYPE_SHARED)) break;
			time_to_str(m->time, time_str, sizeof(time_str));
			printf("0x%016lx %15lu %20s %5d %16x\n",
				(unsigned long)m->addr,
				m->size,
				time_str,
				m->id,
				m->key
			);
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
	for (ind=0x01; ind&(MTYPE_MALLOC | MTYPE_MMAP | MTYPE_SHARED); ind*=2) {
		if (strcmp(arg[1], mblock_type_name[(int)log2((double)ind)]) == 0) {
			break;
		}
		list_mem_print(ind);
	}
	return 0;
}
