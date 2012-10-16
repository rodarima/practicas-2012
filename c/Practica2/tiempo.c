#include "tiempo.h"

/* obtiene la hora actual en microsegundos */
double microsegundos()
{
	struct timeval t;
	if (gettimeofday(&t, 0) < 0 ) return 0.0;
	return (t.tv_usec + t.tv_sec * 1000000.0);
}
/* calcula el tiempo en double que tarda en ejecutarse la funcion */
double medir_tiempo_fvector(struct funcion_t *funcion, int *e)
{
	int (*f)(int [], int) = funcion->f;
	int *v = funcion->v;
	int n = funcion->n;
	int k = funcion->k;
	
	double t;
	int entro = 0;
	t = microsegundos();
	f(v,n);
	t = microsegundos() - t;
	if(t<MIN_MICRO){
		entro=1;
		int i=0;
		
		t = microsegundos();
		for(i=0; i<k; i++){
			f(v,n);
		}
		t = microsegundos()-t;
		
		t=t/((double)k);
	}
	if(e) (*e)=entro;
	return t;
}

