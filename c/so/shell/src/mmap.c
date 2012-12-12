#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "help.h"
#include "mmap.h"
#include "../lib/mblock.h"
#include "global.h"
#include "../lib/list.h"
#include <time.h>

#define handle_error(msg) \
do { perror(msg); return -1 ; } while (0)


int get_prot_from_string(char *ptr_prot)
{
	int prot = PROT_NONE;
	int i;
	int len = strlen(ptr_prot);

	for(i=0; i<len; i++)
	{
		char p = ptr_prot[i];
		switch(p){
		case 'r': prot |= PROT_READ; break;
		case 'w': prot |= PROT_WRITE; break;
		case 'x': prot |= PROT_EXEC; break;
		case '-': break;
		default: return -1;
		}
	}

	return prot;
}

void free_mmap(void *p)
{
	struct mblock_t *s = (struct mblock_t *) p;
	free(s->name);
}

int cmd_mmap(char **arg)
{
	/* mmap fichero [-s] [perm] */

	/* Fichero no especificado */
	if(arg[1] == NULL)
	{
		show_help(arg[0]);
		return -1;
	}

	char *file = arg[1];

	int shared = MAP_PRIVATE;
	int perm = 0;

	/* Opcion -s o permisos */
	if(arg[2] != NULL)
	{
		if(strcmp(arg[2], "-s") == 0)
		{
			shared = MAP_SHARED;
		}
		else
		{
			if((perm = get_prot_from_string(arg[2])) == -1)
			{
				printf("Permisos no reconocidos\n");
				return -1;
			}
		}
	}
	if((arg[2] != NULL) && (arg[3] != NULL))
	{
		if((strcmp(arg[3], "-s") == 0) && (shared == MAP_PRIVATE))
		{
			shared = MAP_SHARED;
		}
		else if((shared == MAP_SHARED) && 
			((perm = get_prot_from_string(arg[2])) == -1))
		{
			printf("Permisos no reconocidos\n");
			return -1;
		}
		else
		{
			printf("Parámetros incorrectos\n");
			show_help(arg[0]);
		}
	}



	char *addr;
	int fd;
	struct stat sb;

	fd = open(file, O_RDONLY);
	if (fd == -1){
		perror("open");
		return -1;
	}

	if (fstat(fd, &sb) == -1)           /* To obtain file size */
	{
		close(fd);
		perror("fstat");
		return -1;
	}

	
	addr = mmap(NULL, sb.st_size, perm, shared, fd, 0);
	if (addr == MAP_FAILED)
	{
		close(fd);
		perror("mmap");
		return -1;
	}

	printf("%p\n", addr);

	struct mblock_t *p = (struct mblock_t *) malloc(sizeof(struct mblock_t));

	if(!p)
	{
		perror("malloc");
		return -1;
	}

	char *fp = malloc(strlen(file));
	if(!fp)
	{
		perror("malloc");
		return -1;
	}
	strcpy(fp, file);
	
	p->addr = addr;
	p->fd = fd;
	p->name = fp;
	p->type = MTYPE_MMAP;
	p->time = time(0);
	p->size = sb.st_size;

	list_insert(list_mem, p, free_mmap, cmp_mblock);

	//list_new(list_mem, sizeof(struct mblock_t), NULL);

	/*
	s = write(STDOUT_FILENO, 0, length);
	if (s != length)
	{
		close(fd);
		if (s == -1)
		{
			perror("write");
			return -1;
		}

		fprintf(stderr, "partial write");
		return -1;
	}
	*/
	return -1;
}

