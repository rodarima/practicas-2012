
CC = gcc -g

XFLAGS = -Wall -O3

CFLAGS = $(XFLAGS)

DIR = sort
PROJECT = libsort.a
OBJECTS = sort.o

all:		$(PROJECT)

$(PROJECT):	$(OBJECTS)
	ar rcs $(PROJECT) $(OBJECTS)
	ln -sf $(DIR)/$(PROJECT) ../$(PROJECT)

sort.o:		sort.c
	$(CC) $(CFLAGS) -c $^

clean:
	rm -f *.o *.a ../$(PROJECT)