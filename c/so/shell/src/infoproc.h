#ifndef INFOPROC_H
#define INFOPROC_H	1

#include "../lib/proc.h"
#include "global.h"
#include <stdio.h>
#include <stdlib.h>

int infoproc(struct proc_t *p);
int cmd_infoproc(char **arg);

#endif
