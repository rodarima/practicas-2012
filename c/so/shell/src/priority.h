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

#ifndef PRIORITY_H
#define PRIORITY_H

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int set_priority(pid_t pid, int prio);
int show_priority(pid_t pid);
int cmd_prio(char **arg);

#endif /* PRIORITY_H */
