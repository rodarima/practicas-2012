#include "cotas.h"

double cota_n(int n, double t)
{
	double nd = n;
	return t/nd;
}
double cota_nlogn(int n, double t)
{
	double nd = n;
	return t/(nd*log(nd));
}
double cota_logn(int n, double t)
{
	double nd = n;
	return t/log(nd);
}
double cota_n_pow_1_8(int n, double t)
{
	double nd = n;
	return t/pow(nd, 1.8);
}
double cota_n_pow_2(int n, double t)
{
	double nd = n;
	return t/pow(nd, 2.0);
}double cota_n_pow_2_2(int n, double t)
{
	double nd = n;
	return t/pow(nd, 2.2);
}
