#ifndef __SHELL_H__
#define __SHELL_H__

#define SPC_DELIM " \n\r\t"
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



void __attribute__ ((constructor)) coolIntro(void);
ssize_t lePrompt(const char *, char **, size_t *);
char *readInput(void);

#endif