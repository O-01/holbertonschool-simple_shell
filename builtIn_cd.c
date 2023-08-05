#include "shell.h"

/**
 * builtIn_cd - changes current working directory
 * @path: desired destination working directory
 * @input: unused argument
 * @argv: argv, used to print error messages
 * Return: 0 upon success, -1 otherwise
 */

int builtIn_cd(char *path, char *input, char **argv)
{
/*	char *olD = NULL, cwd[MAX_LEN];*/

	(void)input;
	(void)argv;
/*
 *	if (getcwd(cwd, sizeof(cwd)))
 *		*cwd = '\0';
 *
 *	if (!path)
 *		path = getenvY("HOME");
 *
 * WIP
 *	if (!strcmp("-", argv[1]))
 *	{
 *		olD = getenvY("OLDPWD");
 *		if (!olD)
 *		{
 *			printf("%s: cd: OLDPWD not set\n", argv[0]);
 *			return (-1);
 *		}
 *		if (chdir("olD"))
 *			printf("%s\n", olD);
 *		return (0);
 *	}
 */
	if (!querY(path))
		chdir(path);

	return (0);
}
