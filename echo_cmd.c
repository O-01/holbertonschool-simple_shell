#include "shell.h"
/**
 * echo_cmd - when echo is used, prints everything after it to stdout
 * @argc: not used here
 * @argv: arguements in the commandline
 */
void echo_cmd(int argc, char *argv[])
{
	int i = 1;

	(void)argc;

	if (argv[0] == "echo")
	{
		for (; argv[i]; i++)
			printf("%s", argv[i]);
		printf("\n");
	}
}
