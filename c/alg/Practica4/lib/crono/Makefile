
CC = gcc -g

XFLAGS = -Wall -O3

CFLAGS = $(XFLAGS)

DIR = crono
PROJECT = libcrono.a
OBJECTS = table.o time.o

all:		$(PROJECT)

$(PROJECT):	$(OBJECTS)
	ar rcs $(PROJECT) $(OBJECTS)
	ln -sf $(DIR)/$(PROJECT) ../$(PROJECT)

table.o: table.c
	$(CC) $(CFLAGS) -c $^

time.o:	time.c
	$(CC) $(CFLAGS) -c $^

clean:
	rm -f *.o *.a ../$(PROJECT)