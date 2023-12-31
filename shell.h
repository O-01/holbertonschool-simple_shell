#ifndef __SHELL_H__
#define __SHELL_H__

#define SPC_DELIM " \t\n\r"
#define PATH_DELIM ":"
#define MAX_LEN 1024

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <errno.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>

extern char **environ;

/**
 * struct builtIn - struct to assist in calling built-in functions
 * @bIn_call: built-in function name
 * @bIn_fnc: function called if input = builtIn_call, NULL otherwise
 */

typedef struct builtIn
{
	char *bIn_call;
	int (*bIn_fnc)();
} bI_t;

void __attribute__ ((constructor)) coolIntro(void);
ssize_t lePrompt(const char *prmptStyle, char **inPut, size_t *len);

/* Input verification / processing tools */
int emptyInput(char *inPut);
char *goFission(char **, char *delim);
int parseInput(char *inPut, char *cmdS[], char *delim);
int querY(char *cmd);
void signalThing(int sig);
char **slashCMD(char **dest, char *cmdS);

/* Environmental variable verification / processing */
char **deColon(char *src, char *chop);
char *getenvY(char *varName);
int hacK(void);
char **obtainPATH(char *cmdS);

/* Exec / process management */
int forkExec(char *input, char *cmd, char **argv);
int spoon(char *input, char *cmd, char **argv);

/* Memory-related functions */
void *_calloc(size_t num, size_t size);
int memCalcPATH(char *patH, char *cmdS);
void freecmdS(char **cmdS);

/* Built-in implementations */
int builtIn(char *cmdS, char *arg, char *input, char **argv);
int builtIn_cd(char *path, char *, char **argv);
int builtIn_env(char *, char *, char **);
int builtIn_exit(char *code, char *input, char **argv);

/* Error handling */
int eX127(char *cmd, char *prog, char *input, char **cmdS);
int eX13(char *cmd, char *prog, char *input, char **cmdS);

/* String helpers */
int _atoi(char *inS);
char *str_concat(char *dest, char *src);

#endif
