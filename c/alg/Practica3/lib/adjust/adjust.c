#include <stdio.h>
#include <stdlib.h>
#include "adjust.h"

struct func_cota_s list_cotas[] =
{
	{ cota_n, "n" },
	{ cota_n_pow_1_05, "n^1.05" },
	{ cota_nlogn, "n*log(n)" },
	{ cota_n_pow_1_2, "n^1.2" },
	{ cota_n_pow_1_5, "n^1.5" },
	{ cota_n_pow_2, "n^2" },
	{ cota_n_pow_5, "n^5" }

};

double getmedia(double *v, int n){
	double acum=0;
	int i;
	for (i = 0; i < n; ++i)
	{
		acum+=v[i];
	}
	return acum/((double)n);
}


double getabs(double n){
	return (n<0) ? -n : n;
}


double getmediana(double *v, int n){
	double media = getmedia(v, n);
	double mediana=v[0];
	int i;
	for(i=0; i<n; i++){
		if(getabs(media - v[i]) < mediana) mediana = v[i];
	}

	return mediana;
}

double getvarianza(double *v, int n, double med){
	int i;
	double acum=0;
	for (i = 0; i <n ; ++i)
	{
		acum += getabs(v[i]-med);
	}
	return (acum/((double)(n-1)));
}

void interpolate(time_value *t, int n){
	int n_cotas=sizeof(list_cotas)/sizeof(struct func_cota_s);
	double *l_adj = malloc(n*sizeof(double));
	double *l_var = malloc(n_cotas*sizeof(double));
	int i,j;
	for (j=0; j<n_cotas; j++){


		for(i=0; i<n; i++){
			l_adj[i] = list_cotas[j].f(t[i].n, t[i].t);
		}
		double mediana = getmediana(l_adj, n);
		//double ref = 1.0/list_cotas[j].f(t[3].n, t[3].t);
		double ref = 1.0/mediana;
		for(i=0; i<n; i++){
			l_adj[i] = ref*list_cotas[j].f(t[i].n, t[i].t);
			//printf("n=%-7d t=%-6.1f adj=%-10.5f v=%-10.5f\n", t[i].n, t[i].t, list_cotas[j].f(t[i].n, t[i].t), l_adj[i]);
		}
		double m = getmedia(l_adj, n);
		double v = getvarianza(l_adj, n, m);
		l_var[j] = v;
		//printf("Funcion: %s Media:%f Varianza:%f \n", list_cotas[j].name, m, v);
	}
	int pos=0;
	for(i=0; i<n_cotas; i++){
		if(l_var[i]<l_var[pos]){
			pos = i;
		}
	}
	printf("La función más acotada es: %s al %d%%\n", list_cotas[pos].name, (int)(100*(1.0-log(1.0+l_var[pos]))));
	/*
	for(i=0; i<n_cotas; i++){
		double lg = log(1.0+l_var[i]);

		double p = (lg>1) ? 0.0 : (100.0*(1.0-lg));
		printf("%s (%5.2f%%)\n", list_cotas[i].name, p);
	}
	*/
	free(l_adj);
	free(l_var);

}

void estimate(time_value *tv, int n)
{
	time_value *t = malloc(n*sizeof(time_value));
	int i = 0;
	for(i=0; i<n; i++){
		t[i].n = tv[i].n;
		t[i].t = tv[i].t;
	}
	interpolate(t, n);
}