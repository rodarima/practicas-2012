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

#ifndef MBLOCK_H
#define MBLOCK_H

#include <sys/types.h>
#include <time.h>

#define MTYPE_MALLOC	0x01
#define MTYPE_MMAP	0x02
#define MTYPE_SHARED	0x04

struct mblock_t
{
	void *addr;
	size_t size;
	time_t time;

	char type;

	union
	{
		int fd;
		key_t key;
	};

	union
	{
		int shmid;
		char *name;
	};

};

extern const char *mblock_type_name[];

int cmp_mblock(void *a, void *b);

#endif
