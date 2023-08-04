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
	int iter = 0;
	char **feedCMD = NULL;

	if (builtIn(cmd, argv[1], input, argv) == 1)
		return (1);
	else if (fileExist(cmd) == 0)
		forkExec(input, cmd, argv);
	else
	{
		feedCMD = obtainPath(cmd);

		for (iter = 0; feedCMD[iter]; iter++)
			if (fileExist(feedCMD[iter]) == 0)
				forkExec(input, feedCMD[iter], argv);

		for (iter = 0; feedCMD[iter]; iter++)
		{
/*			printf("%s\n", feedCMD[iter]);*/
			free(feedCMD[iter]), feedCMD[iter] = NULL;
		}

		free(feedCMD);
	}
	return (0);
}
