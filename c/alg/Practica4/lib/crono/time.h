#ifndef TIME_H_
#define TIME_H_

#include <sys/time.h>


#define MIN_MICRO	50
#define MAX_K		1000

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
		for(__k_counter=0; __k_counter<MAX_K; __k_counter++){	\
			begin;						\
			f;						\
			after;						\
		}							\
		(t)=u_sec()-(t);					\
		double __lost_time=u_sec();				\
		for(__k_counter=0; __k_counter<MAX_K; __k_counter++){	\
			begin;						\
			after;						\
		}							\
		__lost_time = u_sec()-__lost_time;			\
		(t)-=__lost_time;					\
		t=t/k;							\
	}else k=0;							\
} while(0);								\


#endif
