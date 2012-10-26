
CC=gcc

CFLAGS=-Wall -g

#Carpetas de los fuentes y ejecutables
LIB=lib
SRC=src
TEST=test

OBJ_LIB = $(LIB)/*.o


test_cmd: $(LIB)/entrada.o 	\
	$(LIB)/parametros.o 	\
	$(SRC)/comandos.h 	\
	$(TEST)/test_cmd.c 	\
	$(SRC)/pwd.o 		\
	$(SRC)/pid.o 		\
	$(SRC)/delete.o 	\
	$(SRC)/chdir.o 		\
	$(SRC)/list.o		\
	$(SRC)/quit.o 		\
	$(LIB)/usuario.o 	\
	$(LIB)/path.o
	$(CC) $(CFLAGS) $^ -o $(TEST)/test_cmd

quit.o: $(TEST)/test_cmd.h $(SRC)/quit.c
	$(CC) $(CFLAGS) $^ -c $(SRC)/quit.o

test_entrada: $(LIB)/entrada.o $(LIB)/parametros.o $(TEST)/test_entrada.c
	$(CC) $(CFLAGS) $^ -o $(TEST)/test_entrada

test_parametros: $(LIB)/entrada.o $(LIB)/parametros.o $(TEST)/test_parametros.c
	$(CC) $(CFLAGS) $^ -o $(TEST)/test_parametros

test_scandir: $(TEST)/test_scandir.c
	$(CC) $(CFLAGS) $^ -o $(TEST)/test_scandir

clean:
	rm -rf $(LIB)/*.o $(SRC)/*.o $(TEST)/*.o
