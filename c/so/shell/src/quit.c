#include "quit.h"
#include "../test/test_cmd.h"

int cmd_quit(char **argv)
{
	extern int salir_cmd;
	salir_cmd=1;
	return 0;
}

