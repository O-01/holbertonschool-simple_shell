#include "shell.h"

/**
 * builtIn_cd - changes current working directory
 * @path: desired destination working directory
 * @input: unused argument
 * @argv: unused argument
 * Return: 0 upon success, -1 otherwise
 */

int builtIn_cd(char *path, char *input, char __attribute__((unused)) **argv)
{
	(void)input;

	if (!path || fileExist(path) == -1)
		return (-1);

	return (chdir(path));
}
