#include "shell.h"

/**
 * forkExec - launches input command with its arguments
 * @input: command
 * @argv: arguments to the command
 */

void forkExec(char *input, char **argv)
{
	pid_t launch = 0;
	int status = 0;

	launch = fork();

	if (launch == -1)
		perror(argv[0]), exit(EXIT_FAILURE);
	else if (launch == 0)
	{
		if (execvp(argv[0], argv) == -1)
			perror(argv[0]), free(input), exit(EXIT_FAILURE);
	}
	else
		wait(&status);
}
