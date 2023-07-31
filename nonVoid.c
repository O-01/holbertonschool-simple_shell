#include "shell.h"

/**
 * nonVoid - gives the next part of input that is not among defined delimiters
 * @input: input
 * Return: next acceptable instance of input, NULL otherwise
 */

char *nonVoid(char **input)
{
        char *cmdT = NULL;

        while ((cmdT = strsep(input, SPC_DELIM)) && !*cmdT)
                ;

        return (cmdT);
}
