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
	char *cmdS[BUFSIZ] = { NULL };

	while (1)
	{
		signal(SIGINT, signalThing);

		if (lePrompt("# ", &inPut, &inputLen) == -1)
			free(inPut), exit(0);

		dup = strdup(inPut);

		for (iter = 0; dup; iter++)
		{
			cmdT = nonVoid(&dup);
			cmdS[iter] = cmdT;
			if (strcmp("exit", cmdS[0]) == 0)
			{
				freecmdS(inPut, cmdS);
				free(inPut);
				exit(0);
			}
		}

		forkExec(inPut, cmdS);

		free(dup), freecmdS(inPut, cmdS);

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
/*
 *	int iter = 0, spc = 0;
 *
 *	if (input)
 *		for (iter = 0; input[iter]; iter++)
 *			if (input[iter] == ' ' ||
 *			    input[iter] == '\n' ||
 *			    input[iter] == '\t' ||
 *			    input[iter] == '\r')
 *				spc++;
 *
 *	if (input && cmdS)
 *		for (iter = 0; cmdS[iter + spc]; iter++)
 *			cmdS[iter] = NULL;
 */

	if (input && *cmdS)
		free(*cmdS), *cmdS = NULL;
}

/**
 * forkExec - launches input command with its arguments
 * @input: command
 * @argv: arguments to the command
 */

void forkExec(char *input, char **argv)
{
	pid_t launch = 0;
	int status = 0;
	int fileExists = fileExist(argv[1]);

	if (fileExists == 0)
	{
		launch = fork();

		if (launch == -1)
			perror(argv[0]), exit(EXIT_FAILURE);
		else if (launch == 0)
		{
			if (execvp(argv[0], argv) == -1)
				perror(argv[0]), free(input), exit(2);
		}
		else
			wait(&status);
	}
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
	char *prmptStyle = "\n# ";

	if (sig == SIGINT)
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, prmptStyle, strlen(prmptStyle));
}
