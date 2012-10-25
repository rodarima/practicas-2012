
CC=gcc

CFLAGS=-Wall -g

all: 	tiempo.o cotas.o tabla.o sub_max.c
	$(CC) $(CFLAGS) $^ -lm -o sub_max 

clean:
	rm -rf *.o sub_max
