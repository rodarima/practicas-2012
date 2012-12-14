#Carpetas de los fuentes y ejecutables
LIB=lib
SRC=src
TEST=test


#INC=-I$(SRC) -I$(LIB)
#INCO=-L$(SRC) -L$(LIB)

CFLAGS=-Wall -g $(INC) $(INCO)

OBJ_LIB = $(LIB)/*.o

all: 	$(LIB)/entrada.o 	\
	$(LIB)/parametros.o 	\
	$(SRC)/pwd.o 		\
	$(SRC)/pid.o 		\
	$(SRC)/delete.o 	\
	$(SRC)/deltree.o	\
	$(SRC)/chdir.o 		\
	$(SRC)/list.o	 	\
	$(SRC)/quit.o 		\
	$(SRC)/priority.o	\
	$(SRC)/fork.o		\
	$(SRC)/ejecutar.o	\
	$(SRC)/prog.o		\
	$(SRC)/splano.o		\
	$(SRC)/pplano.o		\
	$(SRC)/procesos.o	\
	$(SRC)/borraprocesos.o	\
	$(SRC)/infoproc.o	\
	$(SRC)/help.o		\
	$(LIB)/usuario.o 	\
	$(LIB)/path.o		\
	$(LIB)/carpeta.o 	\
	$(LIB)/list.o 		\
	$(LIB)/arg_prio.o	\
	$(LIB)/proc.o		\
	$(LIB)/mblock.o 	\
	$(SRC)/malloc.o		\
	$(SRC)/free.o		\
	$(SRC)/mem.o		\
	$(SRC)/mmap.o		\
	$(SRC)/munmap.o		\
	$(SRC)/shared.o		\
	$(SRC)/unshared.o	\
	$(SRC)/rmkey.o		\
	$(SRC)/recursiva.o	\
	$(SRC)/memdump.o	\
	$(SRC)/uid.o		\
	$(SRC)/global.h		\
	$(SRC)/comandos.h 	\
	$(SRC)/shell.c 	
	$(CC) $(CFLAGS) $^ -lm -o shell

test_cmd: $(LIB)/entrada.o 	\
	$(LIB)/parametros.o 	\
	$(SRC)/pwd.o 		\
	$(SRC)/pid.o 		\
	$(SRC)/delete.o 	\
	$(SRC)/deltree.o	\
	$(SRC)/chdir.o 		\
	$(SRC)/list.o	 	\
	$(SRC)/quit.o 		\
	$(SRC)/priority.o	\
	$(SRC)/fork.o		\
	$(SRC)/ejecutar.o	\
	$(SRC)/prog.o		\
	$(SRC)/splano.o		\
	$(SRC)/pplano.o		\
	$(SRC)/procesos.o	\
	$(SRC)/borraprocesos.o	\
	$(SRC)/infoproc.o	\
	$(SRC)/help.o		\
	$(LIB)/usuario.o 	\
	$(LIB)/path.o		\
	$(LIB)/carpeta.o 	\
	$(LIB)/list.o 		\
	$(LIB)/arg_prio.o	\
	$(LIB)/proc.o		\
	$(SRC)/global.h		\
	$(SRC)/comandos.h 	\
	$(TEST)/test_cmd.c 	
	$(CC) $(CFLAGS) $^ -o $(TEST)/test_cmd

help:	$(SRC)/help.c $(SRC)/help.h

test_printf: $(TEST)/test_printf

test_open: $(TEST)/test_open

test_entrada: $(LIB)/entrada.o 	\
	$(LIB)/parametros.o 	\
	$(TEST)/test_entrada.c
	$(CC) $(CFLAGS) $^ -o $(TEST)/test_entrada

test_list: $(LIB)/list.o 	\
	$(TEST)/test_list.c
	$(CC) $(CFLAGS) $^ -o $(TEST)/test_list


test_parametros: $(LIB)/entrada.o 	\
		$(LIB)/parametros.o 	\
		$(LIB)/usuario.o 	\
		$(TEST)/test_parametros.c
	$(CC) $(CFLAGS) $^ -o $(TEST)/test_parametros

test_scandir: $(TEST)/test_scandir.c
	$(CC) $(CFLAGS) $^ -o $(TEST)/test_scandir

clean:
	rm -rf $(LIB)/*.o $(SRC)/*.o $(TEST)/*.o $(TEST)/test_cmd $(TEST)/test_entrada $(TEST)/test_parametros $(TEST)/test_scandir shell
