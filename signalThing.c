#include "shell.h"

/**
 * signalThing - defines behavior upon SIGINT, to be fed to signal
 * @sig: signal
 */

void signalThing(int sig)
{
	char *prmptStyle = "\n# ";

	if (sig == SIGINT)
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, prmptStyle, strlen(prmptStyle));
}
