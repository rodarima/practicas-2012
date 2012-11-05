#ifndef TIME_H_
#define TIME_H_

#include <sys/time.h>

/*
 * u_sec:
 * 
 * Obtiene el instante de tiempo actual en microsegundos. Devuelve el resultado
 * en tipo double. En caso de que no se pudiera medir el tiempo devuelve 0.0 .
 * Para obtener la medición del tiempo actual se emplea gettimeofday.
 */
double u_sec();

/*
 * timeof:
 * 
 * Calcula el tiempo que una función f tarda en ejecutarse empleando la función
 * u_sec. A la función f se le pasa un puntero s (habitualmente a una estructura
 * de datos) como parámetro.
 */
double timeof(void (*f)(void *), void *s);

/*
 * time_alg:
 * 
 * Calcula el tiempo que una función tarda en ejecutarse de manera similar a 
 * como lo hace la función timeof, sin embargo recibe un parámetro nuevo, k, que
 * bajo un tiempo inferior a MIN_MICRO realiza una medición más exacta, repi-
 * tiendo las llamadas a f, k veces. Devuelve la media de estas ejecuciones, en
 * caso de que se lleguen a realizar, o simplemente el tiempo con timeof de f.
 * Para indicar el número de iteraciones que se realizaron, se modifica el valor
 * de k con las mismas.
 */
double time_alg(void (*f)(void *), void *s, int *k);

#endif
