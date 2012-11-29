#include "list.h"
#include <stdio.h>

void prim()
{
	list_t l;
	list_init(&l);
	printf("Lista creada!\n");
	list_free(l);
}