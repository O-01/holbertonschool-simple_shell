#include "shell.h"

/**
 * builtIn_env - prints environmental variables
 * @arg: unused argument
 * @input: unused argument
 * @argv: unused argument
 * Return: 0 upon success, -1 otherwise or if env vars N/A
 */

int builtIn_env(char *arg, char *input, char __attribute__((unused)) **argv)
{
	char **ourEnv = NULL;
	int iter = 0;

	(void)arg, (void)input;

	for (ourEnv = environ; *ourEnv; ++ourEnv)
		printf("%s\n", *ourEnv), iter++;

	return (iter > 0 ? 0 : -1);
}
