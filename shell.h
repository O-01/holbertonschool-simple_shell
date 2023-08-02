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

void __attribute__ ((constructor)) coolIntro(void);
ssize_t lePrompt(const char *, char **, size_t *);
void signalThing(int);
int fileExist(char *);
char *goFission(char **, char *delim);
void forkExec(char *, char **);
void freecmdS(char **);
int emptyInput(char *);
int parseInput(char *inPut, char *cmdS[], char *delim);

/* Built-in implementations */
int builtIn_env(void);
int builtIn_cd(char *path);

#endif
