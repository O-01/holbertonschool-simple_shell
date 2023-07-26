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

/*	sleep(3);
	system("clear");*/
}

/**
 *
 *
 */

int main(void)
{
	char *inPut = NULL;
	size_t len = 0;

	lePrompt("Σ ≈ ", &inPut, &len);

	return (0);
}

/**
 *
 *
 */

ssize_t lePrompt(const char *prmptStyle, char **inPut, size_t *len)
{
	ssize_t gotLine = 0;

	fprintf(stderr, "%s(pwd needs to be here) ≈ ", prmptStyle);
	gotLine = getline(inPut, len, stdin);

	return (gotLine);
}
