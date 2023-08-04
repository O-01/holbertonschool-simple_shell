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
	int prmptChk = 0, eXit = 0;
	char *cmdS[MAX_LEN] = { NULL };

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

		if (parseInput(inPut, cmdS, SPC_DELIM) == 1)
			eXit = 1;
		printf("%d - %d\n", access(cmdS[0], F_OK), access(cmdS[0], X_OK));
		printf("%d\n", querY(cmdS[0]));
		spoon(inPut, cmdS[0], cmdS, argv[0]);

		freecmdS(cmdS);
		if (inPut != NULL)
			free(inPut), inPut = NULL;

		if (eXit == 1)
			return (2);

		fflush(stdout);
	}
	return (0);
}
