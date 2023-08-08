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
	int status = 0, flag = 0;

	if (!input || !argv)
		return (-1);

	launch = fork();

	if (launch == -1) /* fork unsuccessful */
		perror(cmd), exit(EXIT_FAILURE);
	else if (launch == 0) /* fork successful */
	{
		if (execve(cmd, argv, environ) == -1) /* execute cmd w/ args */
			perror(cmd), free(input), exit(EXIT_FAILURE);
	}
	else
	{ /* wait for status change in child PID */
		waitpid(launch, &status, 0);
		flag = WEXITSTATUS(status);
		if (flag == 2 && !isatty(STDIN_FILENO))
			freecmdS(argv), free(input), input = NULL, _exit(flag);
	}
	return (1);
}
