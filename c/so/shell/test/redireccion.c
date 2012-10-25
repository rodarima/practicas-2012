#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>


int main(int argc, char **argv)
{
	int fd = open("salida", O_WRONLY | O_CREAT);
	dup2(1, fd);
	
	printf("holaaa");
	
	close(fd);
	
	
	return 0;
}

