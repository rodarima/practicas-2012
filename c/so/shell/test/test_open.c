#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
	int fd = open("test_list.c", O_RDONLY);
	printf("%d\n", fd);
	return 0;
}