#ifndef _CRONO_H
#define _CRONO_H 1

/* Funciones de tabla */

struct time_row_t
{
	int n;
	double t;
	double sub;
	double aj;
	double sob;
	int k;
};

struct time_table_t{
	char *title;
	
	struct time_row_t* time_row;
	int n_rows;
};


void print_table(struct time_table_t *t);
void print_row(struct time_row_t *r);
void print_head();

#endif