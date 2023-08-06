#include "shell.h"

/**
 * querY - checks if a file exists using stat, command query
 * @cmd: file that needs to be checked
 * Return: The status of the requested file: 0 if yes, -1 if negative
 */

int querY(char *cmd)
{
	struct stat buffer;

	return (stat(cmd, &buffer));
}
