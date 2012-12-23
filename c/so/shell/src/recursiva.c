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

#include "recursiva.h"
#include "help.h"

void recursion(int n)
{
	char automatico[512];
	static char estatico[512];
	
	printf("%-10d %p %p %p\n", n, &n, automatico, estatico);
	
	n--;
	if (n > 0) {
		recursion(n);
	}
}

int cmd_recursiva(char **arg)
{
	if (arg[1]==NULL) {
		show_help(arg[0]);
		return -1;
	}
	
	int n = atoi(arg[1]);
	if (n > 0) {
		printf("n                      &n    &automatico &estatico\n");
		recursion(n);
	}else {
		printf("El parámetro nº de llamadas recursivas ha de ser un número mayor que cero\n");
	}

	return 0;
}
