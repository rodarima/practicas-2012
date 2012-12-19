#ifndef TABLA_H
#define TABLA_H
#include <stdio.h>
#include <stdlib.h>
#include "time.h"


struct time_row_t
{
	int n;
	double t;
	double sub;
	double aj;
	double sob;
	int k;
};

struct time_table_t
{
	char *title;
	
	struct time_row_t* time_row;
	int n_rows;
};


void print_table(struct time_table_t *t);
void print_row(struct time_row_t *r);
void print_head();
void print_cotas(char *a, char *b, char *c);

#endif


