#include "shell.h"
/**
 * getPID - returns the PID of the Child/Parents process.
 * Return: 0;
 */
int getPID(void)
{
	pid_t process_id;
	pid_t parentPID;

	process_id = getpid();
	parentPID = getppid();

	printf("PID: %d\n", process_id);
	printf("Parent PID: %d\n", parentPID);

	return (0);
}
