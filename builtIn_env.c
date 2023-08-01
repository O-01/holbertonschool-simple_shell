#include "shell.h"

/**
 * builtIn_env - prints environmental variables
 * Return: 0 upon success, -1 otherwise
 */

int builtIn_env(void)
{
	char **ourEnv = NULL;
	int iter = 0;

	for (ourEnv = environ; *ourEnv; ++ourEnv)
		printf("%s\n", *ourEnv), iter++;

	return (iter > 0 ? 0 : -1);
}
