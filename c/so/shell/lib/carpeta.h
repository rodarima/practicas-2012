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

#ifndef CARPETA_H
#define CARPETA_H



#include <sys/stat.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

char *concatenar_carpeta(char *path, char *path2);
int is_dir(char *dir);

#endif
