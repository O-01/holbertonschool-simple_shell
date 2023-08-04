#include "shell.h"

/**
 * fileExist - checks if a file exists
 * @cmd: file that needs to be checked
 * Return: The status of the requested file
 */

int fileExist(char *cmd)
{
	struct stat buffer;

	return (stat(cmd, &buffer));
}
