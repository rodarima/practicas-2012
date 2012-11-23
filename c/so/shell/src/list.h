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

#ifndef LS_H
#define LS_H

#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <stdlib.h>

#include <dirent.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
#include <sys/time.h>

#include "../lib/carpeta.h"


#define MODO_L	0x01
#define MODO_R	0x02
#define MODO_H	0x04

int cmd_list(char **argv);

#endif /* LS_H */
