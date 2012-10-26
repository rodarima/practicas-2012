#ifndef CARPETA_H
#define CARPETA_H


#include <sys/stat.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

char *concatenar_carpeta(char *path, char *path2);
int is_dir(char *dir);

#endif
