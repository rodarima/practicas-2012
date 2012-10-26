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

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include "comandos.h"

int main(){
	//cmd_pid(0, NULL);
	commands[1].pfunc(NULL);
	return 0;
}
