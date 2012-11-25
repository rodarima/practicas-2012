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

#include "arg_prio.h"
#include "stdio.h"

char *get_arg_prio(char **args)
{
	int i = 1;
	while(args[i])
	{
		i++;
	}
	if(i == 1) return NULL;
	i--;

	char *p = args[i];

	if(p[0] != '@')
	{
		return NULL;
	}
	args[i] = NULL;

	return p+1;
}