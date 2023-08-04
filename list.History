#include "shell.h"
/**
 * history - history list of previous commands used
 * @cmds: command entered
 * @max_size: max size of the struct list
 * @start: start of the list
 */
typedef struct history
{
	char **cmds;
	int max_size;
	int start;
}

/**
 * initHistory - initializes the history list
 * @history: history struct list
 * @size: size of the list
 */
void initHistory(struct history* history, int size)
{
	int i = 0;

	history->max_size = size;
	history->cmds = malloc(sizeof(char) * size);

	for (i = 0; i < szie; i++)
	{
		history->commmands[i] = NULL;
	}
}

/**
 * addHistory - adds newest input/cmd into history list
 * @history: history struct list
 * @line: most recent line received
 */
void addHistory(struct history* history, char* line)
{
	if (history->cmds[history->start] != NULL)
		free(history->cmds[history->start]);

	history->cmds[history->start] = line;
	history->start = (history->begin + 1) % history->max_size;
}

/**
 * printHistory - prints out the previous command from history list
 * @histort: history struct list
 */
void printHistory(struct history* history)
{
	int i = 0;
	int start = history->start;
	
	for (i = 0; i < size; i++)
	{
		if (history->cmds[start] != NULL)
			printf("%s\n", history->cmds[start]);
		start++;
		if (start >= history->max_size)
			start = 0;
	}
}

/**
 * freeHistory - frees the history list
 * @history: history struct list
 */
void freeHistory(struct history* history)
{
	int i = 0;

	for (i = 0; i < size; i++)
	{
		if (history->cmds[i] != NULL)
			free(history->cmds[i]);
	}
	free(history->cmds);
}
