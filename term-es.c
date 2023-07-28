#include "shell.h"

/**
 *
 *
 */

int main(void)
{
	char *inPut = NULL, *tok = NULL, *cpy = NULL;
	size_t len = 0;
	time_t iTime = time(NULL);
	int iter = 0, flag = 0;
	char *cmdS[BUFSIZ];

	fprintf(stderr, "\nWELCOME ~ %s\n", asctime(gmtime(&iTime)));

	while (1)
	{
		signal(SIGINT, signalThing);

		lePrompt("Σ ≈ ", &inPut, &len);

		*cmdS = malloc(sizeof(char *) * BUFSIZ);
		if (!*cmdS)
			return (-1);

		cpy = strndup(inPut, BUFSIZ);

		for (; (tok = voider(&cpy)); iter++)
		{
			cmdS[iter] = tok;
			if (strcmp("exit", cmdS[0]) == 0)
				fprintf(stdout, "BYE BYE\n"),exit(EXIT_SUCCESS);
		}

		forkExec(cmdS[0], cmdS);

		for(iter = 0; cmdS[iter]; iter++)
		{
			if (flag == 1)
				fprintf(stderr, "\n");
			fprintf(stderr, "'%s'", cmdS[iter]);
			flag = 1;
			cmdS[iter] = NULL;
		}

		fprintf(stdout, "\n");
		free(*cmdS), *cmdS = NULL;
		flag = 0, iter = 0;
		fflush(stdout);
	}
	return (0);
}

/**
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
 *
 *
 *
 */

char *voider(char **input)
{
	char *tok = NULL;

	while ((tok = strsep(input, SPC_DELIM)) && !*tok)
		;

	return (tok);
}

/**
 *
 *
 */

int fileExist(char *file)
{
	struct stat buffer;

	return (stat(file, &buffer) == 0);
}
/**
 *
 *
 */
ssize_t lePrompt(const char *prmptStyle, char **inPut, size_t *len)
{
	ssize_t gotLine = 0;
	char cwd[BUFSIZ];

	fprintf(stderr, "%s%s ≈ ", prmptStyle, getcwd(cwd, BUFSIZ));
	gotLine = getline(inPut, len, stdin);
	if (gotLine == EOF)
		fprintf(stderr, "^D\nOK BYE\n"), exit(EXIT_FAILURE);

	return (gotLine);
}

void signalThing(int sig)
{
	char *prmptStyle = "Σ ≈ ";
	char cwd[BUFSIZ];

	if (sig == SIGINT)
		fprintf(stderr, "\n%s%s ≈ ", prmptStyle, getcwd(cwd, BUFSIZ));
}

/**
 *
 *
 */

void __attribute__ ((constructor)) coolIntro(void)
{
	int fileDesc = 0;
	char *buffer;
	ssize_t fileContent = 0, outPut;

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

	sleep(1);
/*	system("clear");*/
}
