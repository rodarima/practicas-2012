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
#include <stdint.h> /* Para SIZE_MAX */

#define SIZE_BLOCK	10
#define SIZE_DATA	(sizeof(node_t))


int list_init_single(list_t *pl)
{
	return list_init(pl, 0);
}

int list_init(list_t *pl, char type)
{

	(*pl) = (list_t) malloc(sizeof(struct list_s));
	if(*pl==NULL) return -1;

	list_t l = (*pl);

	l->n = 0;
	l->type = type;

	l->data = malloc(SIZE_BLOCK*sizeof(void *));
	if(l->data == NULL) return -1;
	*(l->data) = NULL;

	if((type&LIST_CLEAR))
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
		while(*data)
		{
			if(*clear)
			{
				(*clear)(*data);
			}
			free(*data);
			data++;
			clear++;
		}
		printf("friendo %p", l->clear);
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
/*
size_t list_search(list_t l, cmp_func_t *cmp)
{
	size_t inicio = 0;
	size_t final  = (l->n-1);
	size_t mitad;

	while(inicio <= final)
	{
		mitad = (inicio+final)/2;
		int c = (*cmp)(ptr, data[mitad]);
		if(c==-1)
		{
			final = mitad-1;
		}
		else if(c==1)
		{
			inicio = mitad+1;
		}
		else
		{
			return mitad;
		}
	}

	return SIZE_MAX;

}
*/
int list_insert(list_t l, void *ptr, free_func_t *f, cmp_func_t *cmp)
{
	size_t n = l->n+1;
	void **data = l->data;
	free_func_t **clear = l->clear;
	
	if(NEED_REALLOC(n)){
		size_t newsize = (n+SIZE_BLOCK)*sizeof(void*);
		data = realloc(l->data, newsize);
		if(!data) return -1;

		if(clear)
		{
			clear = realloc(l->clear, newsize);
			if(!clear) return -1;
		}
	}


	if(cmp) /* Insertar empleando el algoritmo de busqueda binaria */
	{
		long int inicio = 0;
		long int final  = n-1;
		long int mitad = 0;

		while(inicio<final)
		{
			mitad = (inicio+final)/2;
			int c = (*cmp)(ptr, data[mitad]);
			if(c==-1)
			{
				final = mitad;
			}
			else
			{
				inicio = mitad+1;
			}
		}

		void **pmitad = data+inicio;
		void **pos = data+n-1;

		

		if(clear)
		{
			free_func_t **pmitadf = clear+inicio;
			free_func_t **posf = clear+n-1;
			while(pos != pmitad){
				*pos=*(pos-1);
				*posf=*(posf-1);
				pos--;
				posf--;
			}
			*pmitad = ptr;
			*pmitadf = f;

			data[n] = NULL;
			clear[n] = NULL;

			l->clear = clear;
		}
		else
		{
			while(pos != pmitad){
				*pos=*(pos-1);
				pos--;
			}
			*pmitad = ptr;
			data[n] = NULL;
		}

		l->n = n;
		l->data = data;

	}
	else /* Insertar sin orden */
	{
		data[n-1] = ptr;
		data[n] = NULL;

		if(clear)
		{
			clear[n-1] = f;
			clear[n] = NULL;
			l->clear = clear;
		}

		l->n = n;
		l->data = data;
	}

	return 0;
}

void *list_get(list_t l, size_t n)
{
	return l->data[n];
}

void list_delete(list_t l, size_t i)
{
	free_func_t **baseclear = l->clear;
	free_func_t **fclear = l->clear + i;
	void **idata = l->data + i;

	void **data = l->data;
	free_func_t **clear = l->clear;
	size_t n = l->n;


	/* Si la lista incluye llamadas de borrado */
	if(baseclear)
	{
		/* Si necesitamos llamar a la funcion */
		if(*fclear)
		{
			/* Invocamos a la funcion de borrado */
			(*fclear)(*idata);
		}

		/* Borramos la estructura del dato */
		free(*idata);

		/* Eliminamos el hueco en las listas de data y clear */
		while(*idata)
		{
			*idata = *(idata+1);
			*fclear = *(fclear+1);

			idata++;
			fclear++;
		}

		if(NEED_REALLOC(n))
		{
			size_t newsize = (n + SIZE_BLOCK) * sizeof(void*);
			data = realloc(l->data, newsize);
			clear = realloc(l->clear, newsize);
			if(!data) return;
			if(!clear) return;

			l->data = data;
			l->clear = clear;
		}


	}
	else /* Si no tiene funciones de borrado */
	{
		/* Borramos la estructura del dato */
		free(*idata);

		/* Eliminamos el hueco en las listas de data */
		while(*idata)
		{
			*idata = *(idata+1);
			idata++;
		}

		if(NEED_REALLOC(n))
		{
			size_t newsize = (n + SIZE_BLOCK) * sizeof(void*);
			data = realloc(l->data, newsize);
			if(!data) return;

			l->data = data;
		}

	}

	l->n--;
	return;

	/*
	//printf("Friendo: %p\n", *pos);
	void **pos = l->data+i;
	free_func_t **clear = l->clear;
	free_func_t **cpos = l->clear+i;

	if(cpos)
	{
		(*cpos)(*pos);
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
	*/
}
#undef NEED_REALLOC


/*
list_destroy
list_insert
list_delete
list_search
*/
