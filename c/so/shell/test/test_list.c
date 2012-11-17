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

	/*printf("l=%p l->data=%p l->n=%lu l->data=%p\n", l, l->data, l->n, ((int**)(l->data))[0]);
	int *p = (int *) list_new(l,4);
	*p=888;
	printf("l=%p l->data=%p l->n=%lu l->data[0]=%d p=%p \n", l, l->data, l->n, *((int**)(l->data))[0], p);
	void **f = list_get(l, 0);
	printf("f=%p\n", f);
	list_delete(l, f);
	printf("l=%p l->data=%p l->n=%lu l->data=%p\n f=%p", l, l->data, l->n, ((int**)(l->data)), f);
*/
	int i;
	for(i=0; i<K; i++){
		int* p = list_new(l,4);
		*p=i;
	}
	for(i=0; i<K; i++){
		//int *p = list_get(l, 1);
		//printf("%p\n", p);
		list_delete(l, list_get(l, 0));
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