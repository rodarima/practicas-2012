
CC = gcc -g

XFLAGS = -Wall -O3

CFLAGS = $(XFLAGS)

DIR = graph
PROJECT = libgraph.a
OBJECTS = prim.o list.o

all:		$(PROJECT)

$(PROJECT):	$(OBJECTS)
	ar rcs $(PROJECT) $(OBJECTS)
	ln -sf $(DIR)/$(PROJECT) ../$(PROJECT)

clean:
	rm -f *.o *.a ../$(PROJECT)