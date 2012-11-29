#ifndef _ADJUST_H
#define _ADJUST_H 1

struct val_t
{
	int n;
	double t;
};

typedef struct val_t time_value;

typedef double (*func_cota_t)(int n, double t);

void estimate(time_value *tv, int values);

#endif