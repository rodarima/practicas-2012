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


int list_init_single(list_t *pl)
{
	return list_init(pl, LIST_NO_CLEAR);
}

int list_init(list_t *pl, char type)
{

	(*pl) = (list_t) malloc(sizeof(struct list_s));
	if(*pl==NULL) return -1;

	list_t l = (*pl);

	l->n = 0;
	//l->type = type;

	l->data = malloc(SIZE_BLOCK*sizeof(void *));
	if(l->data == NULL) return -1;
	*(l->data) = NULL;

	if((type&LIST_CLEAR_MASK) == LIST_CLEAR)
	{
		l->clear = malloc(SIZE_BLOCK*sizeof(void **));
		if(l->clear == NULL) return -1;
		*(l->clear) = NULL;
	}
	else
	{
		l->clear = NULL;
	}


	return 0;

}

void list_free(list_t l)
{
	free_func_t **clear = l->clear;
	void **data = l->data;

	if(clear)
	{
		while((*data) && (*clear))
		{
			(*clear)(*data);
			free(*data);
			data++;
			clear++;
		}
		free(l->clear);
	}
	else
	{
		while(*data && *clear)
		{
			free(*data);
			data++;
		}
	}

	free(l->data);

	free(l);

}

#define NEED_REALLOC(n) ((((n)%SIZE_BLOCK)==(SIZE_BLOCK/2)))

void *list_new_single(list_t l, size_t size)
{
	return list_new(l, size, NULL);
}

void *list_new(list_t l, size_t size, free_func_t *f)
{
	size_t n = l->n+1;
	void **data = l->data;
	free_func_t **clear = l->clear;
	
	if(NEED_REALLOC(n)){
		size_t newsize = (n+SIZE_BLOCK)*sizeof(void*);
		data = realloc(l->data, newsize);
		if(!data) return NULL;

		if(clear)
		{
			clear = realloc(l->clear, newsize);
			if(!clear) return NULL;
		}
	}

	void *d = malloc(size);
	if(!d) return NULL;

	data[n-1] = d;
	data[n] = NULL;

	if(clear)
	{
		clear[n-1] = f;
		clear[n] = NULL;
		l->clear = clear;
	}

	l->n = n;
	l->data = data;

	return d;
}

void *list_get(list_t l, size_t n)
{
	return l->data[n];
}

void list_delete(list_t l, size_t i)
{
	//printf("Friendo: %p\n", *pos);
	void **pos = l->data+i;
	free_func_t **clear = l->clear;
	if(clear)
	{
		(*clear)(*pos);
	}
	free(*pos);
	while(*pos!=NULL){
		*pos=*(pos+1);
		pos++;
	}

	size_t n = l->n;
	void **data = l->data;
	if(NEED_REALLOC(n))
	{
		size_t newsize = (n+SIZE_BLOCK)*sizeof(void*);
		data = realloc(l->data, newsize);
		if(!data) return;

		if(clear)
		{
			clear = realloc(l->clear, newsize);
		}
		if(!clear) return;
	}

	if(clear)
	{
		l->clear = clear;
	}

	l->data = data;
	l->n--;
}
#undef NEED_REALLOC


/*
list_destroy
list_insert
list_delete
list_search
*/
