#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "help.h"

#define handle_error(msg) \
do { perror(msg); exit(EXIT_FAILURE); } while (0)


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


int cmd_mmap(char **argv)
{
	/* mmap fichero [-s] [perm] */

	/* Fichero no especificado */
	if(argv[1] == NULL)
	{
		show_help(argv[0]);
	}

	char *file = argv[1];

	char *shared = NULL;
	char *perm = NULL;

	/* Opcion -s o permisos */
	if(argv[2] != NULL)
	{
		if(strcmp(argv[2], "-s") == 0)
		{
			shared = argv[2];
		}
		else
		{
			perm = argv[2];
		}
	}

	if(argv[3])

	char *addr;
	int fd;
	struct stat sb;
	off_t offset, pa_offset;
	size_t length;
	ssize_t s;

	if (argc < 3 || argc > 4) {
		fprintf(stderr, "%s file offset [length]\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		handle_error("open");

if (fstat(fd, &sb) == -1)           /* To obtain file size */
	handle_error("fstat");

	offset = atoi(argv[2]);
	pa_offset = offset & ~(sysconf(_SC_PAGE_SIZE) - 1);
/* offset for mmap() must be page aligned */

	if (offset >= sb.st_size) {
		fprintf(stderr, "offset is past end of file\n");
		exit(EXIT_FAILURE);
	}

	if (argc == 4) {
		length = atoi(argv[3]);
		if (offset + length > sb.st_size)
			length = sb.st_size - offset;
/* Can't display bytes past end of file */

} else {    /* No length arg ==> display to end of file */
		length = sb.st_size - offset;
	}

	addr = mmap(NULL, length + offset - pa_offset, PROT_READ,
		MAP_PRIVATE, fd, pa_offset);
	if (addr == MAP_FAILED)
		handle_error("mmap");

	s = write(STDOUT_FILENO, addr + offset - pa_offset, length);
	if (s != length) {
		if (s == -1)
			handle_error("write");

		fprintf(stderr, "partial write");
		exit(EXIT_FAILURE);
	}

	exit(EXIT_SUCCESS);
}

