#include "shell.h"

/**
 * main - infinite loop for prompt
 * Return: Always 0
 */

int main(void)
{
	char *inPut = NULL, *tok = NULL, *cpy = NULL;
	size_t inputLen = 0;
	/*time_t iTime = time(NULL);*/
	int iter = 0/*, flag = 0*/;
	char *cmdS[MAX_LEN];

	/*fprintf(stdout, "WELCOME ~ %s\n", asctime(gmtime(&iTime)));*/

	while (1)
	{
		signal(SIGINT, signalThing);

		lePrompt("Σ ≈ ", &inPut, &inputLen);

/*		*cmdS = malloc(sizeof(char *) * BUFSIZ);
		if (!*cmdS)
			return (-1);
*/
		cpy = malloc(sizeof(char) * strlen(inPut));

		cpy = strdup(inPut);

		for (iter = 0; (tok = voider(&cpy)); iter++)
		{
			cmdS[iter] = tok;
			if (strcmp("exit", cmdS[0]) == 0)
				/*fprintf(stdout, "BYE BYE\n"),*/exit(EXIT_SUCCESS);
		}

		free(cpy);

		forkExec(cmdS[0], cmdS);

		for(iter = 0; cmdS[iter]; iter++)
		{
/*			if (flag == 1)
				fprintf(stderr, "\n");
			fprintf(stderr, "'%s'", cmdS[iter]);
			flag = 1;*/
			cmdS[iter] = NULL;
		}

/*		fprintf(stdout, "\n");*/
		*cmdS = NULL;
		free(*cmdS);
/*		flag = 0;*/
		fflush(stdout);
	}
	return (0);
}

/**
 * forkExec - launches input command with its arguments
 * @cmd: command
 * @argv: arguments to the command
 */

void forkExec(char *cmd, char **argv)
{
	pid_t launch = 0;
	int status = 0;

	launch = fork();

	if (launch == -1)
		perror(cmd), exit(EXIT_FAILURE);
	else if (launch == 0)
	{
		if (execvp(cmd, argv) == -1)
			perror(cmd), exit(EXIT_FAILURE);
	}
	else
		wait(&status);
}

/**
 * voider - voids invalid characters from input
 * @input: input
 * Return: Always token
 */

char *voider(char **input)
{
	char *tok = NULL;

	while ((tok = strsep(input, SPC_DELIM)) && !*tok)
		;

	return (tok);
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
 * lePrompt - gets line from input and maintains prompt
 * @prmptStyle: How we want the prompt to look
 * @inPut: input received from stdin
 * @len: the length of the input from stdin
 * Return: the number of characters read
 */

ssize_t lePrompt(const char *prmptStyle, char **inPut, size_t *len)
{
	ssize_t gotLine = 0;

	if (isatty(STDIN_FILENO))
		fprintf(stdout, "%s", prmptStyle);
	gotLine = getline(inPut, len, stdin);
	if (gotLine == EOF)
		/*fprintf(stderr, "^D\nOK BYE\n"), */exit(EXIT_SUCCESS);

	return (gotLine);
}

/**
 * signalThing - checks for SIGINT
 * @sig: signal
 */

void signalThing(int sig)
{
	char *prmptStyle = "Σ ≈ ";

	if (sig == SIGINT)
		fprintf(stdout, "\n%s", prmptStyle);
}

/**
 * coolIntro - intro splash screen
 *
void __attribute__ ((constructor)) coolIntro(void)
{
	int fileDesc = 0;
	char *buffer;
	ssize_t fileContent = 0, outPut;

	fprintf(stderr, "\033[3J\033[H\033[2J");

	fileDesc = open("intro", O_RDONLY);
	if (fileDesc == -1)
		return;

	buffer = malloc(sizeof(char) * BUFSIZ);
	if (buffer == NULL)
	{
		close(fileDesc);
		return;
	}

	fileContent = read(fileDesc, buffer, BUFSIZ);
	close(fileDesc);
	if (fileContent == -1)
		return;

	outPut = write(STDOUT_FILENO, buffer, fileContent);
	free(buffer);
	if (outPut != fileContent)
		return;

	sleep(3);
	fprintf(stdout, "\033[3J\033[H\033[2J");
}*/
