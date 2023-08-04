#include "shell.h"
/**
 *
 *
 *
 */
typedef struct history_s
{
	char *command;
	struct history_s *prev;
	struct history_s *next;
} history_t;

-------------------------------

char * addHistory(char *cmd);

-------------------------------

char * addHistory(char *cmd)
{

