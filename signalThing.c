#include "shell.h"

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
