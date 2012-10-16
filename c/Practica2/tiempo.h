#ifndef TIEMPO_H
#define TIEMPO_H

#include <sys/time.h>

#define MIN_MICRO	500
#define MAX_K		10000

double microsegundos();
double medir_tiempo_fvector(struct funcion_t *funcion, int *e);

#endif
