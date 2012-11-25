#ifndef BORRAPROCESOS_H
#define BORRAPROCESOS_H 1

#include "../lib/proc.h"

void free_cmd_proc(struct proc_t *p);
void free_cmd_proc_list();
int cmd_borraprocesos(char **arg);

#endif