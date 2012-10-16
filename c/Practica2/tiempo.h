/*
 * Tiempo.h
 *
 *  Created on: 04/10/2012
 *      Author: rodrigo
 */

#ifndef TIEMPO_H_
#define TIEMPO_H_

#include <sys/time.h>

#define MIN_MICRO	500
#define MAX_K		10000

double medir_tiempo_fvector(int (*f)(int [], int), int v[], int n, int *entro);

#endif /* TIEMPO_H_ */
