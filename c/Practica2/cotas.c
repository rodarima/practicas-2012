#include "cotas.h"

double cota_n(int n, double t)
{
	double nd = n;
	return t/nd;
}
double cota_nlogn(int n, double t)
{
	double nd = n;
	return t/nd*log(nd);
}