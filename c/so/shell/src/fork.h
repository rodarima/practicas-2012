#ifndef FORK_H
#define FORK_H

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int cmd_fork(char **arg);

#endif
