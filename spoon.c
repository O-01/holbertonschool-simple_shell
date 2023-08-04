#include "shell.h"

/**
 * spoon - manages input cmd, filtering through builtIn & fileExist, then
 * calling forkExec if file exists & can be accessed
 * @input: CLI input
 * @cmd: the first element of input & command to be run, if possible
 * @argv: vector of arguments retrieved from input
 * @prog: name of program, passed to error functions
 * Return: 0 upon success, 1 if built-in called, -1 upon error
 */

int spoon(char *input, char *cmd, char **argv, char *prog)
{
	int iter = 0, flag = 0;
	char **feeD = NULL;

	if (builtIn(cmd, argv[1], input, argv) == 1)
		return (1);
	if (!querY(cmd))
	{
		if (!access(cmd, X_OK))
			forkExec(input, cmd, argv);
		else
		{
			perror(cmd);
			if (isatty(STDIN_FILENO) == 0)
				free(input), input = NULL, exit(13);
		}
	}
	else
	{
		feeD = obtainPath(cmd);
		if (!feeD)
			eX127(cmd, prog, input);
		for (iter = 0; feeD[iter]; iter++)
			if (!querY(feeD[iter]) && !access(feeD[iter], X_OK))
			{
				forkExec(input, feeD[iter], argv), flag = 1;
				break;
			}
		for (iter = 0; feeD[iter]; iter++)
			free(feeD[iter]), feeD[iter] = NULL;
		free(feeD);
		if (flag == 0)
			eX127(cmd, prog, input);
	}
	return (0);
}
