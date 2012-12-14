#ifndef CMD_MEMDUMP_H
#define CMD_MEMDUMP_H 

#include <stddef.h>

void dump(char *p, size_t bytes);
int cmd_memdump(char **arg);

#endif