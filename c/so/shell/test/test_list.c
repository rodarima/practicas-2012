#include "../lib/list.h"
#include <stdio.h>
#include <string.h>

#define K	100

struct cosa
{
	char *a;
	char *b;
	char *c;
	int n;
};

void borra_cosas(void *p)
{
	struct cosa *s = (struct cosa *) p;
	free(s->a);
	free(s->b);
	free(s->c);
}
int cmp_cosas(void *a, void *b)
{
	struct cosa *pa = (struct cosa *)a;
	struct cosa *pb = (struct cosa *)b;

	if(pa->n < pb->n) return -1;
	else if(pa->n > pb->n) return 1;
	else return 0;
}



int main()
{
	list_t l;
	if(list_init(&l, LIST_CLEAR)){
		perror("No se pudo crear la lista");
		return -1;
	}


	printf("l=%p l->data=%p l->n=%lu l->data=%p\n", 
				l, l->data, l->n, ((int**)(l->data))[0]);

	int i;
	for(i=0; i<K; i++)
	{
		struct cosa *p = malloc(sizeof(struct cosa));

		p->a = malloc(10);
		p->b = malloc(10);
		p->c = malloc(10);
		p->n = i*5;
		strcpy(p->a, "aaaa");
		strcpy(p->b, "bbbbb");
		strcpy(p->c, "cccccc");
		list_insert(l, p, borra_cosas, cmp_cosas);
	}

	struct cosa *p = malloc(sizeof(struct cosa));

	p->a = malloc(10);
	p->b = malloc(10);
	p->c = malloc(10);
	p->n = 20;
	strcpy(p->a, "aaaa");
	strcpy(p->b, "bbbbb");
	strcpy(p->c, "cccc20");
	list_insert(l, p, borra_cosas, cmp_cosas);

	for(i=0; i<K; i++){
		struct cosa *s = (struct cosa *) list_get(l, i);
		printf("l->data[%d]=%p a=%s b=%s c=%s d=%d\n",
				i, list_get(l, i), s->a, s->b, s->c, s->n);
	}
	
	for(i=0; i<K/2; i++)
	{
		list_delete(l, 0);
	}

	for(i=0; i<K/2; i++){
		struct cosa *s = (struct cosa *) list_get(l, i);
		printf("l->data[%d]=%p a=%s b=%s c=%s d=%d\n",
				i, list_get(l, i), s->a, s->b, s->c, s->n);
	}



	list_free(l);
	return 0;
}
