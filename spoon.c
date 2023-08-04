#include "shell.h"

/**
 * spoon - manages input cmd, filtering through builtIn & fileExist, then
 * calling forkExec if file exists & can be accessed
 * @input: CLI input
 * @cmd: the first element of input & command to be run, if possible
 * @argv: vector of arguments retrieved from input
 * Return: 0 upon success, 1 if built-in called, -1 upon error
 */

int spoon(char *input, char *cmd, char **argv)
{
	int iter = 0, flag = 0;
	char **feedCMD = NULL;

	if (builtIn(cmd, argv[1], input, argv) == 1)
		return (1);
	if (fileExist(cmd) == 0)
	{
		if (access(cmd, X_OK) == 0)
			forkExec(input, cmd, argv);
		else
		{
			perror(cmd);
			if (isatty(STDIN_FILENO) == 0)
				exit(13);
		}
	}
	else
	{
		feedCMD = obtainPath(cmd);
		if (!feedCMD && isatty(STDIN_FILENO) == 0)
			perror(cmd), exit(127);
		else if (!feedCMD)
			return (-1);
		for (iter = 0; feedCMD[iter]; iter++)
			if (fileExist(feedCMD[iter]) == 0 &&
			    access(feedCMD[iter], X_OK) == 0)
			{
				forkExec(input, feedCMD[iter], argv), flag = 1;
				break;
			}
		for (iter = 0; feedCMD[iter]; iter++)
			free(feedCMD[iter]), feedCMD[iter] = NULL;
		free(feedCMD);
		if (flag == 0)
			perror(cmd);
	}
	return (0);
}
