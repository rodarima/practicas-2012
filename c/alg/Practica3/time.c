#include <sys/time.h>

//typedef void (*funct_void)(void *);	

double u_sec()
{
	struct timeval t;
	if (gettimeofday(&t, 0) < 0 ) return 0.0;
	return (t.tv_usec + t.tv_sec * 1000000.0);
}


double timeof(void (*f)(void *), void *s)
{
	double temp = u_sec();
	f(s);
	return u_sec() - temp;
}


double time_alg(void (*f)(void *), void *s, int *k)
{
	double t = timeof(f,s);
	int i;
	
	if(t < MIN_MICRO)
	{
		t = 0;
		for(i=0; i<(*k); i++) t += timeof(f,s);
		t = t / ((double)k);
	}
	else
	{
		(*k) = 1;
	}
	return t;
}
