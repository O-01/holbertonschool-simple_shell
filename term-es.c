#include "shell.h"

/**
 * main - infinite loop for prompt
 * Return: Always 0
 */

int main(void)
{
	char *inPut = NULL;
	size_t inputLen = 0;
	int prmptChk = 0;
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

		parseInput(inPut, cmdS);

		forkExec(inPut, cmdS);

		freecmdS(cmdS);

		if (inPut != NULL)
			free(inPut), inPut = NULL;

		fflush(stdout);
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
