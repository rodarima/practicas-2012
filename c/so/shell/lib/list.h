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

#ifndef LIST_H
#define LIST_H

#include <stdlib.h>

//typedef void *node_t;

struct list_s
{
	size_t n;
	void **data;
};

typedef struct list_s *list_t;

int list_init(list_t *pl);
void list_free(list_t l);

void *list_new(list_t l, size_t size);
void *list_get(list_t l, size_t n);
void list_delete(list_t l, void **pos);

#endif /* LIST_H */
