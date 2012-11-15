
CC = gcc -g

LIBDIR = lib
INCDIR = include

INCF = -I$(INCDIR)
LIBF = -L$(LIBDIR)

XFLAGS = -Wall -g -O3

CFLAGS = $(XFLAGS) $(INCF) $(LIBF)

LIB = lib

LIBRARIES = sort crono adjust



all: 	$(LIBRARIES) testsort

$(LIBRARIES):
	$(MAKE) --directory=$(LIB)/$@

testsort: testsort.c sort crono adjust
	$(CC) $(CFLAGS) testsort.c -o testsort -lsort -lcrono -ladjust -lm

clean: clean-libs
	rm -f *.o testsort

clean-libs:
	for d in $(LIBRARIES); do $(MAKE) --directory=$(LIB)/$$d clean;	done
