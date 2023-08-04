#include "shell.h"

/**
 * forkExec - launches input command with its arguments
 * @input: command
 * @cmd: command name used for error messages
 * @argv: arguments to the command
 * Return: 1 upon success, -1 if input or cmd NULL
 */

int forkExec(char *input, char *cmd, char **argv)
{
	pid_t launch = 0;
	int status = 0;

	if (!input || !argv)
		return (-1);

	launch = fork();

	if (launch == -1)
		perror(cmd), exit(EXIT_FAILURE);
	else if (launch == 0)
	{
		if (execvp(cmd, argv) == -1)
			perror(cmd), free(input), exit(EXIT_FAILURE);
	}
	else
		wait(&status);

	return (1);
}
