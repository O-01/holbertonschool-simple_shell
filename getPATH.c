#include "shell.h"
/**
 * getPath - Looks for and scans environmental variables
 * @input : input to be received
 */
void getPATH(char **input)
{
	char *start = *input;
	char *VarVal, *VarName;
	char *pos, *end;
	int len = 0;

	while ((start = strchr(start, '$')))
	{
		end = strchr(start, ' ');
		if (!(end))
			end = start + strlen(start);

		len = end - start;

		VarName = strndup(start + 1, len - 1);

		VarVal = getenv(VarName);

		if (VarVal)
		{
			*input = strdup(*input);
			pos = *input + (start - *input);
			memmove(pos + strlen(VarVal), end, strlen(end) + 1);
			memcpy(pos, VarVal, strlen(VarVal));
			start = pos + strlen(VarVal);
		}
	else
		start++;

	free(VarName);
	}
}
