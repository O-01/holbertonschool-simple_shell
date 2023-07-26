#ifndef __SHELL_H__
#define __SHELL_H__

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <readline/readline.h>
#include <readline/history.h>

void __attribute__ ((constructor)) coolIntro(void);
void lePrompt(void);

#endif
