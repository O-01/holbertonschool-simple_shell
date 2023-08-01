#include "shell.h"

/**
 * main - infinite loop for prompt
 * Return: Always 0
 */

int main(void)
{
	char *inPut = NULL, *cmdT = NULL, *dup = NULL;
	size_t inputLen = 0;
	int iter = 0, prmptChk = 0;
	char *cmdS[BUFSIZ] = { NULL };

	while (1)
	{
		signal(SIGINT, signalThing);

		prmptChk = lePrompt("# ", &inPut, &inputLen);
		if (prmptChk == -1)
			free(inPut), exit(0);
		else if (prmptChk == 1)
			continue;
		if (emptyInput(inPut) == 0)
		{
			free(inPut), inPut = NULL;
			continue;
		}
		else
		{
			dup = inPut;
			for (iter = 0; (cmdT = nonVoid(&dup)); iter++)
			{
				cmdS[iter] = cmdT;
				if (strcmp("exit", cmdS[0]) == 0)
				{
					freecmdS(cmdS);
					if (inPut)
						free(inPut);
					exit(0);
				}
			}

			if (cmdT != NULL)
				cmdT = NULL;

			forkExec(inPut, cmdS);

			freecmdS(cmdS);

			if (inPut != NULL)
				free(inPut), inPut = NULL;
			if (dup != NULL)
				free(dup), dup = NULL;

			fflush(stdout);
		}
	}
	return (0);
}

/**
 * freecmdS - frees memory related to cmdS argv created in main
 * @cmdS: argument vector
 */

void freecmdS(char **cmdS)
{
	int iter = 0;

	for (iter = 0; cmdS[iter]; iter++)
		cmdS[iter] = NULL;

	if (*cmdS)
		free(*cmdS), *cmdS = NULL;
}

/**
 * fileExist - checks if a file exists
 * @file: file that needs to be checked
 * Return: The status of the requested file
 */

int fileExist(char *file)
{
	struct stat buffer;

	return (stat(file, &buffer) == 0);
}
