#include <sys/types.h>
#include <time.h>

#define MTYPE_MALLOC	0
#define MTYPE_MMAP	1
#define MTYPE_SHARED	2

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
		int id;
		char *name;
	};

};