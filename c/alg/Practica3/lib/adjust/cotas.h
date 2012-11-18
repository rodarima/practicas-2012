#ifndef COTAS_H
#define COTAS_H

#include <math.h>


static inline double cota_n(int n, double t)
{
	double nd = n;
	return t/nd;
}
static inline double cota_nlogn(int n, double t)
{
	double nd = n;
	return t/(nd*log(nd));
}
static inline double cota_logn(int n, double t)
{
	double nd = n;
	return t/(log(nd));
}





static inline double cota_n_pow_0_95(int n, double t)
{
	double nd = n;
	return t/pow(nd,0.95);
}
static inline double cota_n_pow_1_05(int n, double t)
{
	double nd = n;
	return t/pow(nd, 1.05);
}
static inline double cota_n_pow_1_2(int n, double t)
{
	double nd = n;
	return t/pow(nd, 1.2);
}
static inline double cota_n_pow_1_5(int n, double t)
{
	double nd = n;
	return t/pow(nd, 1.5);
}
static inline double cota_n_pow_1_8(int n, double t)
{
	double nd = n;
	return t/pow(nd, 1.8);
}

static inline double cota_n_pow_1_9(int n, double t)
{
	double nd = n;
	return t/pow(nd,1.9);
}

static inline double cota_n_pow_2(int n, double t)
{
	double nd = n;
	return t/pow(nd, 2.0);
}

static inline double cota_n_pow_2_1(int n, double t)
{
	double nd = n;
	return t/pow(nd,2.1);
}

static inline double cota_n_pow_2_2(int n, double t)
{
	double nd = n;
	return t/pow(nd, 2.2);
}

static inline double cota_n_pow_5(int n, double t)
{
	double nd = n;
	return t/pow(nd, 5);
}




static inline double cota_nlog_n_pow_0_9(int n, double t)
{
	double nd = n;
	return t/pow(nd*log(nd),0.9);
}

static inline double cota_nlog_n_pow_1_1(int n, double t)
{
	double nd = n;
	return t/pow(nd*log(nd),1.1);
}


#endif
