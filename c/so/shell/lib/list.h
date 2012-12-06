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

#define LIST_NO_CLEAR	0x00
#define LIST_CLEAR	0x01
#define LIST_CLEAR_MASK	0x01

//typedef void *node_t;

typedef void free_func_t(void *);

struct list_s
{
	size_t n;
	//char type;
	void **data;
	free_func_t **clear;
};

typedef struct list_s *list_t;


/*
 * Inicializa una list_t reservando espacio para el primer bloque, estableciendo
 * a NULL el primer elemento y n a cero.
 * Recibe un puntero a una list_t y devuelve 0 si todo va bien o -1 si hay un 
 * error en la asignación de memoria. Crea una lista sin punteros a funciones de
 * borrado, util cuando el tipo de dato no requiere una eliminacion especial.
 */
int list_init_single(list_t *pl);

/*
 * Inicializa una list_t reservando espacio para el primer bloque, estableciendo
 * a NULL el primer elemento y n a cero.
 * Recibe un puntero a una list_t y devuelve 0 si todo va bien o -1 si hay un 
 * error en la asignación de memoria. El argumento type especifica si se trata
 * de una lista con funciones de borrado o no.
 */
int list_init(list_t *pl, char type);


/*
 * Fríe por completo todos los elementos que necesiten ser freidos en un nodo 
 * si se trata de una lista con funciones de borrado. A continuación borra la
 * estructura de nodo realizando un free. Realiza estos pasos por cada elemento
 * de la lista y a continuación borra toda la estructura de control de la lista.
 * Recibe una list_t y no devuelve nada.
 */
void list_free(list_t l);


/*
 * Reserva espacio para un nuevo elemento en la lista
 * Sólo hace realloc si es necesario crear un nuevo bloque de elementos
 * Recibe una list_t y un size_t (el tamaño del elemento que se quiere insertar)
 * Devuelve un puntero al nuevo espacio asignado de tamaño size o NULL si no hay
 * memoria. 
 */
void *list_new_single(list_t l, size_t size);

/*
 * Reserva espacio para un nuevo elemento en la lista
 * Sólo hace realloc si es necesario crear un nuevo bloque de elementos
 * Recibe una list_t y un size_t (el tamaño del elemento que se quiere insertar)
 * Devuelve un puntero al nuevo espacio asignado de tamaño size o NULL si no hay
 * memoria. Además establece la funcion de borrado correspontiente a f.
 */
void *list_new(list_t l, size_t size, free_func_t *f);


/*
 * Obtiene la direccion de memeoria de un nodo de la lista, que de ha creado con
 * list_get, no la direccion de memoria del puntero que hay en la lista, si no 
 * su valor. Es equivalente a l->data[n]
 */
void *list_get(list_t l, size_t n);


/*
 * Elimina un elemento de la lista. Reajusta los bloques de elementos si es
 * necesario
 * Recibe una list_t y un size_t i, que es la posicion del elemento a eliminar.
 */
void list_delete(list_t l, size_t i);
 
#endif /* LIST_H */
