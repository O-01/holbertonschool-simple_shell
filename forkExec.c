#include "shell.h"

/**
 * forkExec - launches input command with its arguments
 * @input: command
 * @cmd: command name used for error messages
 * @argv: arguments to the command
 * @eXit: exit flag received from main
 * Return: 1 upon success, -1 if input or cmd NULL
 */

int forkExec(char *input, char *cmd, char **argv, int eXit)
{
	pid_t launch = 0;
	int status = 0, flag = 0;

	if (!input || !argv)
		return (-1);

	launch = fork();

	if (launch == -1)
		perror(cmd), exit(EXIT_FAILURE);
	else if (launch == 0)
	{
		if (execve(cmd, argv, environ) == -1)
			perror(cmd), free(input), exit(EXIT_FAILURE);
	}
	else
	{
		waitpid(launch, &status, 0);
		flag = WEXITSTATUS(status);
		if (flag == 2 && eXit == 1 && !isatty(STDIN_FILENO))
			freecmdS(argv), free(input), input = NULL, exit(2);
	}

	return (1);
}
