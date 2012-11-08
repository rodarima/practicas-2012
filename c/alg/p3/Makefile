
CC = gcc -g

XFLAGS = -Wall -g -O3

CFLAGS = $(XFLAGS) $(INCDIR)





testsort: testsort.c sort.o
	$(CC) $(CFLAGS) $^ -o testsort



libsort.so: sort.c
	$(CC) $(CFLAGS) -fPIC -c -o sort.o sort.c
	ld -o libsort.so sort.o -shared 
	export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/home/rodrigo/svn/c/alg/Practica3
#	rm sort.o

practica3: practica3.c tiempo.o tabla.o
	$(CC) $(CFLAGS) $^ -lm -o practica3
#	$(CC) $(CFLAGS) $^ -L/home/rodrigo/svn/c/alg/Practica3 -lsort -o testsort


testsortasm: testsort.c sort.o
	$(CC) -S $(CFLAGS) $^ -o testsort.s
#	$(CC) $(CFLAGS) $^ -L/home/rodrigo/svn/c/alg/Practica3 -lsort -o testsort


all: 	tiempo.o cotas.o tabla.o sub_max.c
	$(CC) $(CFLAGS) $^ -lm -o sub_max 

clean:
	rm -rf *.o testsort
