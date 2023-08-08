#include "shell.h"

/**
 * main - infinite loop responsible for prompt, calling parse/launch functions,
 * & error messages, if necessary
 * @argc: argument count, unused for now
 * @argv: vector of arguments passed on run
 * Return: 0, always
 */

int main(int __attribute__((unused)) argc, char **argv)
{
	char *inPut = NULL;
	size_t inputLen = 0;
	int prmptChk = 0, done = 0;
	char *cmdS[MAX_LEN] = { NULL };

	while (1)
	{
		signal(SIGINT, signalThing); /* provides response to ^C */

		/* display prompt, getline operations */
		prmptChk = lePrompt("# ", &inPut, &inputLen);
		if (prmptChk == -1) /* upon EOF */
			free(inPut), exit(0);
		else if (prmptChk == 1) /* input is single line break */
			continue;
		if (!emptyInput(inPut)) /* input contains only whitespace */
		{
			free(inPut), inPut = NULL;
			continue;
		}
		/* input processing */
		parseInput(inPut, cmdS, SPC_DELIM);

		/* parsed input vector verified for possible execution */
		done = spoon(inPut, cmdS[0], cmdS);
		if (done == 13) /* permission denied */
			eX13(cmdS[0], argv[0], inPut, cmdS);
		if (done == 127) /* file/command not found */
			eX127(cmdS[0], argv[0], inPut, cmdS);

		freecmdS(cmdS); /* free parsed input vector */
		if (inPut != NULL)
			free(inPut), inPut = NULL;

		/* clear stdout buffer, displaying contents */
		fflush(stdout);
	}
	return (0);
}
