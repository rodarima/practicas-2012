#include "../lib/list.h"
#include <stdio.h>

#define K	100

int main()
{
	list_t l;
	if(list_init(&l)){
		perror("No se pudo crear la lista");
		return -1;
	}

	int i;
	for(i=0; i<K; i++){
		list_new(l,4);
	}

	/*
	printf("l=%p l->data=%p l->n=%lu l->data[0]=%p\n", l, l->data, l->n, ((int**)(l->data))[0]);
	int *p = (int *) list_new(l,4);
	*p=2;
	printf("l=%p l->data=%p l->n=%lu l->data[0]=%d p=%p \n", l, l->data, l->n, *((int**)(l->data))[0], p);
	p = (int *) list_new(l,4);
	*p=24;
	printf("l=%p l->data=%p l->n=%lu *(l->data[1])=%d p=%p \n", l, l->data, l->n, *((int**)(l->data))[1], p);
	p = (int *) list_new(l,4);
	*p=33;
	printf("l=%p l->data=%p l->n=%lu *(l->data[1])=%d p=%p \n", l, l->data, l->n, *((int**)(l->data))[2], p);
	*/



	list_free(l);
	//printf("l=%p l->data=%p l->n=%lu l->data[0]=%p\n", l, l->data, l->n, ((int**)(l->data))[0]);
	return 0;
}