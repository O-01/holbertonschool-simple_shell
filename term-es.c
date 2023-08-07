#include "shell.h"

/**
 * main - infinite loop for prompt
 * @argc: argument count, unused for now
 * @argv: vector of arguments passed on run
 * Return: Always 0
 */

int main(int __attribute__((unused)) argc, char **argv)
{
	char *inPut = NULL;
	size_t inputLen = 0;
	int prmptChk = 0, done = 0;
	char *cmdS[MAX_LEN] = { NULL };

	while (1)
	{
		signal(SIGINT, signalThing);

		prmptChk = lePrompt("# ", &inPut, &inputLen);
		if (prmptChk == -1)
			free(inPut), printf("\n"), exit(0);
		else if (prmptChk == 1)
			continue;
		if (emptyInput(inPut) == 0)
		{
			free(inPut), inPut = NULL;
			continue;
		}

		parseInput(inPut, cmdS, SPC_DELIM);

		done = spoon(inPut, cmdS[0], cmdS);
		if (done == 13)
			eX13(cmdS[0], argv[0], inPut, cmdS);
		if (done == 127)
			eX127(cmdS[0], argv[0], inPut, cmdS);

		freecmdS(cmdS);
		if (inPut != NULL)
			free(inPut), inPut = NULL;

		fflush(stdout);
	}
	return (0);
}
