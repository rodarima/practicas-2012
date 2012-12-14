#!/bin/bash

FIRST_LINE="/*"
FILE_LIST=$(find . -name '*.[ch]')
FILE_CMP="list.c"

HEADER=$(head -n 1 $FILE_CMP)

if [ "$HEADER" == "$FIRST_LINE" ]
then
	echo "Ya hay cabecera en $FILE_CMP"
else
	echo "Añadiendo cabecera a $FILE_CMP"
fi;

#LINES=$(wc -l HEADER | awk '{print $1}')
#cat hola | cat HEADER - | tee hola
