#include "shell.h"

/**
 * builtIn_cd - changes current working directory
 * @path: desired destination working directory
 * Return: 0 upon success, -1 otherwise
 */

/* This is a rough draft - completion to follow */
/* Possible argv[] integration for '-', '.', '..', etc. */
int builtIn_cd(char *path)
{
	return (chdir(path));
}
