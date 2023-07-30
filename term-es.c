#include "shell.h"

/**
 * main - infinite loop for prompt
 * Return: Always 0
 */

int main(void)
{
	char *inPut = NULL, *cmdT = NULL, *dup = NULL;
	size_t inputLen = 0;
	int iter = 0;
	char *cmdS[MAX_LEN] = { NULL };

	while (1)
	{
		signal(SIGINT, signalThing);

		if (lePrompt("Σ ≈ ", &inPut, &inputLen) == -1)
			free(inPut), exit(0);

		dup = strndup(inPut, strlen(inPut));

		for (iter = 0; dup; iter++)
		{
			cmdT = nonVoid(&dup);
			cmdS[iter] = cmdT;
			if (strcmp("exit", cmdS[0]) == 0)
				freecmdS(inPut, cmdS), free(inPut), exit(0);
		}

		free(dup);

		forkExec(cmdS[0], cmdS);

		freecmdS(inPut, cmdS);

		fflush(stdout);
	}
	return (0);
}

/**
 * freecmdS - frees memory related to cmdS argv created in main
 * @input: unaltered line populated from getline
 * @cmdS: argument vector
 */

void freecmdS(char *input, char **cmdS)
{
	int iter = 0, spc = 0;

	if (input)
		for (iter = 0; input[iter]; iter++)
			if (input[iter] == ' ' ||
			    input[iter] == '\n' ||
			    input[iter] == '\t' ||
			    input[iter] == '\r')
				spc++;

	if (cmdS)
	{
		for (iter = 0; cmdS[iter + spc]; iter++)
			free(cmdS[iter]), cmdS[iter] = NULL;

	/*if (*cmdS)
		free(*cmdS);*/
	}
}

/**
 * forkExec - launches input command with its arguments
 * @cmd: command
 * @argv: arguments to the command
 */

void forkExec(char *cmd, char **argv)
{
	pid_t launch = 0;
/*	int status = 0;*/

	launch = fork();

	if (launch == -1)
		perror(cmd), exit(EXIT_FAILURE);
	else if (launch == 0)
	{
		if (execvp(cmd, argv) == -1)
			perror(cmd), exit(EXIT_FAILURE);
	}
	else
		wait(NULL);
}

/**
 * nonVoid - gives the next part of input that is not among defined delimiters
 * @input: input
 * Return: next acceptable instance of input, NULL otherwise
 */

char *nonVoid(char **input)
{
	char *cmdT = NULL;

	while ((cmdT = strsep(input, SPC_DELIM)) && !*cmdT)
		;

	return (cmdT);
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

/**
 * signalThing - checks for SIGINT
 * @sig: signal
 */

void signalThing(int sig)
{
	char *prmptStyle = "Σ ≈ ";

	if (sig == SIGINT)
		if (isatty(STDIN_FILENO))
			fprintf(stderr, "\n%s", prmptStyle);
}
