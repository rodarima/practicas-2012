
CC=gcc

CFLAGS=-Wall -g

libsort.so: libsort.c
	$(CC) $(CFLAGS) -fPIC -c -o libsort.o libsort.c
	ld -o libsort.so libsort.o -shared 
	export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/home/rodrigo/svn/c/alg/Practica3
#	rm libsort.o

testsort: testsort.c libsort.o
	$(CC) $(CFLAGS) $^ -o testsort
#	$(CC) $(CFLAGS) $^ -L/home/rodrigo/svn/c/alg/Practica3 -lsort -o testsort

testsortasm: testsort.c libsort.o
	$(CC) -S $(CFLAGS) $^ -o testsort.s
#	$(CC) $(CFLAGS) $^ -L/home/rodrigo/svn/c/alg/Practica3 -lsort -o testsort


all: 	tiempo.o cotas.o tabla.o sub_max.c
	$(CC) $(CFLAGS) $^ -lm -o sub_max 

clean:
	rm -rf *.o sub_max
