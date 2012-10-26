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

#ifndef ENTRADA_H
#define ENTRADA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define MAX_LEER_LINEA 100

//Lee una línea desde "fichero" y la devuelve sin el "\n"
char * leer_linea(FILE * fichero);

//Lee una linea entera desde "fichero" y la devuelve incluyendo el "\n"
char * leer_linea_n(FILE * fichero);

#endif
