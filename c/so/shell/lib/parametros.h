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

#ifndef PARAMETROS_H
#define PARAMETROS_H

/* Empleamos la funcion leer_linea para leer una linea de la entrada
 * estándar */
#include "entrada.h"

/* Caracteres por donde se troceará */
#define ARGS_DELIM " \t"	

/* Devuelve un puntero a (char *) con los argumentos de str y finalmente
 * termina con un puntero NULL */
char **obtener_argumentos(char *str);
int limpiar_argumentos(char **arg);


#endif /* PARAMETROS_H */
