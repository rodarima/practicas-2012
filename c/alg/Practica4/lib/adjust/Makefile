
CC = gcc -g

XFLAGS = -Wall -O3

CFLAGS = $(XFLAGS)

DIR = adjust
PROJECT = libadjust.a
OBJECTS = adjust.o

all:		$(PROJECT)

$(PROJECT):	$(OBJECTS)
	ar rcs $(PROJECT) $(OBJECTS)
	ln -sf $(DIR)/$(PROJECT) ../$(PROJECT)

clean:
	rm -f *.o *.a ../$(PROJECT)