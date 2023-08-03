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

		parseInput(inPut, cmdS, SPC_DELIM);

		obtainPath(cmdS[0]);

		forkExec(inPut, cmdS);

		freecmdS(cmdS);

		if (inPut != NULL)
			free(inPut), inPut = NULL;

		fflush(stdout);
	}
	return (0);
}
