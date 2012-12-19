#ifndef _CRONO_H
#define _CRONO_H 1


#define MIN_MICRO	500
#define MAX_K		1000

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

/*
 * u_sec:
 * 
 * Obtiene el instante de tiempo actual en microsegundos. Devuelve el resultado
 * en tipo double. En caso de que no se pudiera medir el tiempo devuelve 0.0 .
 * Para obtener la medición del tiempo actual se emplea gettimeofday.
 */
double u_sec();

#define timeof(t, k, f, begin, after) do {				\
	begin;								\
	(t)=u_sec();							\
	f;								\
	(t)=u_sec()-(t);						\
	after;								\
	if(t<MIN_MICRO){						\
		int __k_counter;					\
		(t)=u_sec();						\
		for(__k_counter=0; __k_counter<(k); __k_counter++){	\
			begin;						\
			f;						\
			after;						\
		}							\
		(t)=u_sec()-(t);					\
		double __lost_time=u_sec();				\
		for(__k_counter=0; __k_counter<(k); __k_counter++){	\
			begin;						\
			after;						\
		}							\
		__lost_time = u_sec()-__lost_time;			\
		(t)-=__lost_time;					\
		t=t/k;							\
	}else k=0;							\
} while(0);								\



#endif
