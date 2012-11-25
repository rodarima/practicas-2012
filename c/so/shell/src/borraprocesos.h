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

#ifndef BORRAPROCESOS_H
#define BORRAPROCESOS_H 1

#include "../lib/proc.h"

void free_cmd_proc(struct proc_t *p);
void free_cmd_proc_list();
int cmd_borraprocesos(char **arg);

#endif