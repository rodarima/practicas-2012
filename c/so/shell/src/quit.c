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

#include "quit.h"
#include "../test/test_cmd.h"

int cmd_quit(char **argv)
{
	extern int salir_cmd;
	salir_cmd=1;
	return 0;
}

