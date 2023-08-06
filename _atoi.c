#include "shell.h"

/**
 * _atoi - converts string to integer
 * @inS: input object string to be converted
 * Return: converted output string
 */

int _atoi(char *inS)
{
	int iter = 0, polar = 1, yes = 0;
	size_t out = 0;

	for (iter = 0; inS[iter] != '\0'; iter++)
	{
		if (inS[iter] == '-')
			polar = -(polar);

		while (inS[iter] >= '0' && inS[iter] <= '9')
		{
			out = (out * 10) + (inS[iter] - '0');
			iter++, yes = 1;
		}

		if (yes == 1)
			break;
	}
	return (out * polar);
}
