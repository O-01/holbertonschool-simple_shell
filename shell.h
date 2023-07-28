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

void __attribute__ ((constructor)) coolIntro(void);
ssize_t lePrompt(const char *, char **, size_t *);
char *readInput(void);
void signalThing(int sig);
int fileExist(char *file);
char *nonVoid(char **input);
void forkExec(char *, char **);

#endif
