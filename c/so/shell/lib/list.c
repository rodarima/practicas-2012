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

#include "list.h"
#include <stdlib.h>
#include <stdio.h>
#define SIZE_BLOCK	10
#define SIZE_DATA	(sizeof(node_t))



int list_init(list_t *pl)
{

	(*pl) = (list_t) malloc(sizeof(struct list_s));
	if(*pl==NULL) return -1;

	list_t l = (*pl);

	l->n = 0;
	l->data = malloc(SIZE_BLOCK*sizeof(void *));

	if(l->data == NULL){
		return -1;
	}
	*(l->data) = NULL;
	return 0;

}

void list_free(list_t l)
{
	void **pos = l->data;
	
	while(*pos){
		free(*pos);
		pos++;
	}
	free(l->data);
	free(l);

}
#define NEED_REALLOC(n) ((((n)%SIZE_BLOCK)==(SIZE_BLOCK/2)))
void *list_new(list_t l, size_t size)
{
	size_t n = l->n+1;
	void **p = l->data;
	if(NEED_REALLOC(n)){
		size_t newsize = (n+SIZE_BLOCK)*sizeof(void*);
		p = realloc(l->data, newsize);
		if(!p) return NULL;
	}

	void *d = malloc(size);
	if(!d) return NULL;

	p[n-1] = d;
	p[n] = NULL;
	l->n = n;
	l->data = p;

	return d;
}

void *list_get(list_t l, size_t n)
{
	return (l->data)+n;
}

void list_delete(list_t l, void **pos)
{
	//printf("Friendo: %p\n", *pos);
	free(*pos);
	while(*pos!=NULL){
		*pos=*(pos+1);
		pos++;
	}

	size_t n = l->n;
	void **p = l->data;
	if(NEED_REALLOC(n)){
		size_t newsize = (n+SIZE_BLOCK)*sizeof(void*);
		p = realloc(l->data, newsize);
		if(!p) return;
	}
	l->data=p;
	l->n--;
}
#undef NEED_REALLOC


/*
list_destroy
list_insert
list_delete
list_search
*/
