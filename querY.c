#include "shell.h"

/**
 * querY - checks if a file exists, command query
 * @cmd: file that needs to be checked
 * Return: The status of the requested file
 */

int querY(char *cmd)
{
	struct stat buffer;

	return (stat(cmd, &buffer));
}
