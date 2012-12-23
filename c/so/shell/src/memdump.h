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

#ifndef CMD_MEMDUMP_H
#define CMD_MEMDUMP_H 

#include <stddef.h>

void dump(char *p, size_t bytes);
int cmd_memdump(char **arg);

#endif