
CC = gcc -g

LIBDIR = lib
INCDIR = include

INCF = -I$(INCDIR)
LIBF = -L$(LIBDIR)

XFLAGS = -Wall -g -O3

CFLAGS = $(XFLAGS) $(INCF) $(LIBF)

LIB = lib

LIBRARIES = crono graph



all: 	$(LIBRARIES) testprim

$(LIBRARIES):
	$(MAKE) --directory=$(LIB)/$@

testprim: testprim.c crono graph
	$(CC) $(CFLAGS) testprim.c -o testprim -lcrono -lgraph -lm

clean: clean-libs
	rm -f *.o testprim

clean-libs:
	for d in $(LIBRARIES); do $(MAKE) --directory=$(LIB)/$$d clean;	done
