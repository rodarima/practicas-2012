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

#ifndef INFOPROC_H
#define INFOPROC_H	1

#include "../lib/proc.h"
#include "global.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int infoproc(struct proc_t *p);
int cmd_infoproc(char **arg);

#endif
