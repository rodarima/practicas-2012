#include "cotas.h"

double cota_n(int n, double t)
{
	return t/n;
}
double cota_nlogn(int n, double t)
{
	return t/n*log(n);
}