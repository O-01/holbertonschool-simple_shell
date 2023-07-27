#include "shell.h"

/**
 *
 *
 */

int main(void)
{
	char *inPut = NULL, *separ = NULL;
	size_t len = 0;
	pid_t launch = 0;
	int iter = 0, status = 0;
	char *cmdS[BUFSIZ] = {"/usr/bin/ls", "-laS", NULL, "./"};
	char *cmdT[BUFSIZ];

	while (1)
	{
		signal(SIGINT, signalThing);
		lePrompt("Σ ≈ ", &inPut, &len);
	/*	fprintf(stdout, "%s", inPut); */

		for (; inPut; ++iter)
		{
			separ = strsep(&inPut, SPC_DELIM);
			cmdT[iter] = separ;
			/*fprintf(stdout, "%s\n", separ);*/
			if (strcmp("exit", separ) == 0)
				exit(EXIT_SUCCESS);
			if (strcmp("ls", separ) == 0)
			{
				cmdS[2] = cmdT[2];
				launch = fork();
				if (launch < 0)
					exit(EXIT_FAILURE);
				else if (launch == 0)
				{
					execv("/bin/ls", cmdS);
					perror("No worky");
					exit(EXIT_FAILURE);
				}
				else
					waitpid(launch, &status, 0);
			}
		}
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
