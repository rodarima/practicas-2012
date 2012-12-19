#include "table.h"

void print_row(struct time_row_t *r)
{
	printf("%9d%15.3f%15.6f%15.6f%15.6f%9d\n", 
		r->n, 
		r->t, 
		r->sub, 
		r->aj, 
		r->sob, 
		r->k
	);
	return;
}

void print_head()
{
	printf("\
        n           t(n)      t(n)/h(n)      t(n)/g(n)      t(n)/f(n)        k\
\n");
}

void print_cotas(char *a, char *b, char *c)
{
	printf("Cotas: h(n)=%s, g(n)=%s, f(n)=%s\n", a,b,c);
}

void print_table(struct time_table_t *t)
{
	printf("%s\n", t->title);
	printf("\
        n           t(n)      t(n)/h(n)      t(n)/g(n)      t(n)/f(n)        k\
\n");
	
	int i;
	for(i=0; i<t->n_rows; i++){
		print_row(t->time_row);
	}
	return;
}
