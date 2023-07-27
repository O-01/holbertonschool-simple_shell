#include "shell.h"

/**
 *
 *
 */

int main(void)
{
	char *inPut = NULL;
	size_t len = 0;
	pid_t launch = 0;
	int iter = 1, status = 0;
	char *cmdS[BUFSIZ];
	char *cmdT;

	while (1)
	{
		signal(SIGINT, signalThing);
		lePrompt("Σ ≈ ", &inPut, &len);
		fprintf(stderr, "%s", inPut);

		cmdT = strsep(&inPut, SPC_DELIM);
		if (strcmp("exit\0", cmdT) == 0)
			exit(EXIT_SUCCESS);

		for (; inPut; ++iter)
			cmdS[iter] = strsep(&inPut, SPC_DELIM);

		if (fileExist(cmdT) == 0)
		{
			launch = fork();
			if (launch < 0)
				perror("ERROR"), exit(EXIT_FAILURE);
			if (launch == 0)
			{
				if (execvp(cmdT, cmdS) < 0)
					perror("ERROR");
			}
			else
				wait(&status);
		}
		*cmdS = NULL;
		cmdT = NULL;
		fflush(stdout);
	}
	return (0);
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
