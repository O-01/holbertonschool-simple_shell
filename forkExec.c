#include "shell.h"

/**
 * forkExec - launches input command with its arguments
 * @input: command
 * @cmd: command name used for error messages
 * @argv: arguments to the command
 */

void forkExec(char *input, char *cmd, char **argv)
{
	pid_t launch = 0;
	int status = 0;

	if (!input || !argv)
		return;

	launch = fork();

	if (launch == -1)
		perror(cmd), exit(EXIT_FAILURE);
	else if (launch == 0)
	{
		if (execve(cmd, argv, NULL) == -1)
			perror(cmd), free(input), exit(EXIT_FAILURE);
	}
	else
		wait(&status);
}
