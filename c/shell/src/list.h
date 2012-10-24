#ifndef LIST_H
#define LIST_H

#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <stdlib.h>

#include <dirent.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
#include <sys/time.h>


#define MODO_L	0x01
#define MODO_R	0x02
#define MODO_H	0x04

int cmd_list(char **argv);

#endif /* LIST_H */
