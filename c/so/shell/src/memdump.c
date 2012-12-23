/* 
 *  AUTORES:
 * 	* Carlos Pérez Ramil
 * 	* Rodrigo Arias Mallo
 * 
 *  GRUPO:
 * 	2.3.2
 * 
 *  HORARIO:
 * 	Viernes de 8:30 a 10:30
 */

#include <stddef.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "help.h"

#define BYTES_PER_ROW	16
#define BYTES_COL	8
#define BUFFER_LEN	80
#define SECOND_POS	25
#define TEXT_START_POS	50
#define TEXT_START_POS2	59

/*

mmap Makefile r
memdump 

*/

void dump(char *p, size_t bytes)
{
	size_t rows = (bytes+BYTES_PER_ROW-1)/BYTES_PER_ROW;
	size_t n=0, y, x;

	char buffer[BUFFER_LEN];
	
	for(y=0; y<rows; y++)
	{
		memset(buffer, 0, BUFFER_LEN);
		for(x = 0; (x<BYTES_COL); x++)
		{
			if(n<bytes)
			{
				char c = *p;
				p++;
				n++;

				sprintf(buffer+(3*x), "%02x ", (unsigned char)c);
				if(isprint(c)) buffer[TEXT_START_POS+x]=c;
				else buffer[TEXT_START_POS+x] = '.';
			}
			else
			{
				sprintf(buffer+(3*x), "   ");
				buffer[TEXT_START_POS+x] = ' ';
			}
		}
		for(x = 0; (x<BYTES_COL); x++)
		{
			if(n<bytes)
			{
				char c = *p;
				p++;
				n++;

				sprintf(buffer+(SECOND_POS+3*x), "%02x ", (unsigned char)c);
				if(isprint(c)) buffer[TEXT_START_POS2+x]=c;
				else buffer[TEXT_START_POS2+x] = '.';
			}
			else
			{
				sprintf(buffer+(SECOND_POS+3*x), "   ");
				buffer[TEXT_START_POS2+x] = ' ';
			}
		}

		buffer[SECOND_POS-1] = ' ';
		buffer[TEXT_START_POS-1]=' ';
		buffer[TEXT_START_POS2-1]=' ';
		buffer[BUFFER_LEN-1] = 0;
		printf("%s\n", buffer);
	}
}

int cmd_memdump(char **arg)
{
	if(arg[1]==NULL)
	{
		show_help(arg[0]);
		return -1;
	}

	if(!(arg[1][0]=='0' && (arg[1][1]=='x' || arg[1][1]=='X')))
	{
		printf("La dirección debe comenzar con 0x\n");
		return -1;
	}

	char *p = (char *)strtoul(arg[1], NULL, 16);
	size_t n = 25;

	if(arg[2])
	{
		n = (size_t) strtoul(arg[2], NULL, 10);
	}
	
	dump(p, n);

	return 0;
}