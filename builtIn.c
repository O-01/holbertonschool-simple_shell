#include "shell.h"

/**
 * builtIn - manages built-in functions & calls them upon matching input
 * @cmdS: command to be verified against list of built-in functions
 * @arg: argument to built-in
 * @input: CLI input to be passed to a function call, if necessary
 * @argv: argument vector parsed from input, to be freed when passed to exit
 * Return: 1 if function called, else 0
 */

int builtIn(char *cmdS, char *arg, char *input, char **argv)
{
	bI_t bIn[] = {
		{"cd", builtIn_cd},
		{"env", builtIn_env},
		{"exit", builtIn_exit},
/*	WIP	{"help", NULL},*/
		{NULL, NULL}
	};
	int iter = 0, size = 0;

	if (cmdS) /* command verified against built-in function calls */
		for (iter = 0, size = (sizeof(bIn) / sizeof(bI_t));
		     iter < (size - 1);
		     iter++)
			if (!strcmp(bIn[iter].bIn_call, cmdS))
			{ /* corresponding function called upon match */
				bIn[iter].bIn_fnc(arg, input, argv);
				return (1);
			}
	return (0);
}
