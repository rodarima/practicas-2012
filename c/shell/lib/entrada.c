#include "entrada.h"

//Lee una línea desde "fichero" y la devuelve sin el "\n"
char * leer_linea(FILE * fichero){

	int total = 0, fin = 0;
	char buffer[MAX_LEER_LINEA];
	char *linea = NULL;
	
	/* Lee hasta MAX_BUFFER_READ-1 caracteres incluyendo el \n y 
	 * añade un \0*/
	while((!fin) && (fgets(buffer, MAX_LEER_LINEA, fichero) != NULL)){
		
		int num_caracteres = strlen(buffer);
		
		if((num_caracteres>0) && (buffer[num_caracteres-1] == '\n')){
			buffer[num_caracteres-1] = '\0';
			num_caracteres--;
			fin = 1;
		}
		
		linea = realloc(linea, total+num_caracteres+1);
		
		if(!linea) {
			perror("Realloc ha fallado");
			exit(-1);
		}
		
		strncpy(linea+total, buffer, num_caracteres);
		total += num_caracteres;
		*(linea+total)='\0';
	
	}

	return linea;
}

//Lee una linea entera desde "fichero" y la devuelve incluyendo el "\n"
char * leer_linea_n(FILE * fichero){

	int total = 0, fin = 0;
	char buffer[MAX_LEER_LINEA];
	char *linea = NULL;
	
	/* Lee hasta MAX_BUFFER_READ-1 caracteres incluyendo el \n y 
	 * añade un \0*/
	while(!fin && (fgets(buffer, MAX_LEER_LINEA, fichero) != NULL)){
		int num_caracteres = strlen(buffer);
		if((num_caracteres>0) && (buffer[num_caracteres-1] == '\n')){
			fin = 1;
		}
		linea = realloc(linea, total+num_caracteres+1);
		if(!linea) {
			perror("Realloc ha fallado");
			exit(-1);
		}
		strncpy(linea+total, buffer, num_caracteres);
		total += num_caracteres;
		*(linea+total)='\0';
	}

	return linea;
}

