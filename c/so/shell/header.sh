#!/bin/bash

FIRST_LINE="/*"
FILE_LIST=$(find . -name '*.[ch]')
FILE_CMP="list.c"

for i in $FILE_LIST; do
	HEADER=$(head -n 1 $i)
	
	if [ "${HEADER:0:2}" == "$FIRST_LINE" ]
	then
		echo "Ya hay cabecera en $i"
	else
		echo "Añadiendo cabecera a $i"
		cat HEADER $i > file_tmp_
		mv -v file_tmp_ $i
	fi;
done

#LINES=$(wc -l HEADER | awk '{print $1}')
#cat hola | cat HEADER - | tee hola
