#include "shell.h"

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

/**
 *
 *
 */

int main(void)
{
	char *inPut = NULL;
	size_t len = 0;
	int status = 0;

	while (lePrompt("Σ ≈ ", &inPut, &len))
	{
/*		signal(SIGINT, signalThing);*/
		status = stat;
	}

	return (0);
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
