#include "../lib/list.h"
#include <stdio.h>
#include <string.h>

#define K	100

struct cosa
{
	char *a;
	char *b;
	char *c;
};

void borra_cosas(void *p)
{
	struct cosa *s = (struct cosa *) p;
	free(s->a);
	free(s->b);
	free(s->c);
}



int main()
{
	list_t l;
	if(list_init(&l, LIST_CLEAR)){
		perror("No se pudo crear la lista");
		return -1;
	}


	printf("l=%p l->data=%p l->n=%lu l->data=%p\n", l, l->data, l->n, ((int**)(l->data))[0]);

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
		struct cosa *p = (struct cosa *) list_new(l, sizeof(struct cosa), borra_cosas);

		p->a = malloc(10);
		p->b = malloc(10);
		p->c = malloc(10);
		strcpy(p->a, "aaaa");
		strcpy(p->b, "bbbbb");
		strcpy(p->c, "cccccc");

	}

	for(i=0; i<K; i++){
		struct cosa *s = (struct cosa *) list_get(l, i);
		printf("l->data[%d]=%p a=%s b=%s c=%s\n", i, list_get(l, i), s->a, s->b, s->c);
	}
	
	for(i=0; i<K/2; i++){
		//int *p = list_get(l, 1);
		//printf("%p\n", p);
		list_delete(l, 0);
	}

	for(i=0; i<K/2; i++){
		struct cosa *s = (struct cosa *) list_get(l, i);
		printf("l->data[%d]=%p a=%s b=%s c=%s\n", i, list_get(l, i), s->a, s->b, s->c);
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