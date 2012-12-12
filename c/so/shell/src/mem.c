#include "mem.h"
#include "global.h"
#include "../lib/mblock.h"
#include "../lib/list.h"
#include "help.h"

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
		char entro = 0;
		while (pos<list_mem->n) {

			m = list_get(list_mem, pos);
			if (!(m->type&MTYPE_MALLOC)) break;

			if(entro == 0){
				printf("Espacios reservados con malloc:\n");
				printf("DIRECCIÓN                   TAMAÑO INSTANTE\n");
				entro++;
			}
			
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
		char entro = 0;
		while (pos<list_mem->n) {
			m = list_get(list_mem, pos);
			if (!(m->type&MTYPE_MMAP)) break;
			if(entro == 0){
				printf("Espacios reservados con mmap:\n");
				printf("DIRECCIÓN          TAMAÑO   INSTANTE             FD NOMBRE\n");
				entro++;
			}
			time_to_str(m->time, time_str, sizeof(time_str));
			printf("0x%016lx %-8lu %-20s %2d %s\n",
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
		char entro = 0;
		while (pos<list_mem->n) {
			m = list_get(list_mem, pos);
			if (!(m->type&MTYPE_SHARED)) break;
			if(entro == 0)
			{
				printf("Espacios reservados con shared:\n");
				printf("DIRECCIÓN                   TAMAÑO             INSTANTE ID  KEY\n");
				entro++;
			}
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
	if (arg[1] == NULL) {
		list_mem_print(MTYPE_MALLOC | MTYPE_MMAP | MTYPE_SHARED);
		return 0;
	}

	
	char ind;
	for (ind=0x01; ind&(MTYPE_MALLOC | MTYPE_MMAP | MTYPE_SHARED); ind = ind<<1) {
		if (strcmp(arg[1], mblock_type_name[(int)log2((double)ind)]) == 0) {
			break;
		}
	}
	if(ind & (MTYPE_MALLOC | MTYPE_MMAP | MTYPE_SHARED))
	{
		list_mem_print(ind);
	}
	else
	{
		show_help(arg[0]);
	}
/*
	char ind;
	for (ind=0x01; ind&(MTYPE_MALLOC | MTYPE_MMAP | MTYPE_SHARED); ind = ind<<1) {
		if (strcmp(arg[1], mblock_type_name[(int)log2((double)ind)]) == 0) {
			break;
		}
	}
	list_mem_print(ind);
*/	
	return 0;
}
