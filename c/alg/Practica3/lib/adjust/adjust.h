#ifndef _ADJUST_H
#define _ADJUST_H 1

#include <math.h>
#include "cotas.h"

struct val_t
{
	int n;
	double t;
};

typedef struct val_t time_value;

typedef double (*func_cota_t)(int n, double t);
struct func_cota_s
{
	func_cota_t f;
	char *name;
};





void estimate(time_value *tv, int values, double (*f)(int, double));

#endif