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


/*
 * Inicializa una list_t reservando espacio para el primer bloque, estableciendo
 * a NULL el primer elemento y n a cero.
 * Recibe un puntero a una list_t y devuelve 0 si todo va bien o -1 si hay un 
 * error en la asignación de memoria.
 */
int list_init(list_t *pl);


/*
 * Fríe por completo una list_t
 * Recibe una list_t y no devuelve nada
 */
void list_free(list_t l);


/*
 * Reserva espacio para un nuevo elemento en la lista
 * Sólo hace realloc si es necesario crear un nuevo bloque de elementos
 * Recibe una list_t y un size_t (el tamaño del elemento que se quiere insertar)
 * Devuelve un puntero a la nueva posición
 */
void *list_new(list_t l, size_t size);


/*
 * Obtiene un elemento de la lista
 * Recibe una list_t y un size_t (que es la posición del elemento deseado)
 * Devuelve un puntero al elemento deseado
 */
void *list_get(list_t l, size_t n);


/*
 * Elimina un elemento de la lista. Reajusta los bloques de elementos si es
 * necesario
 * Recibe una list_t y un (void **) que es un puntero a la dirección del
 * elemento a eliminar. No de vuelve nada
 */
void list_delete(list_t l, void **pos);
 
#endif /* LIST_H */
