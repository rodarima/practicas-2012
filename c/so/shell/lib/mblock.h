#include <sys/types.h>
#include <time.h>

#define M

struct mblock_t
{
	void *addr;
	size_t size;
	time_t time;

	char type;

};