#include "time.h"

//typedef void (*funct_void)(void *);	

double u_sec()
{
	struct timeval t;
	if (gettimeofday(&t, 0) < 0 ) return 0.0;
	return (t.tv_usec + t.tv_sec * 1000000.0);
}


