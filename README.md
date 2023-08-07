# *TERM_ES* - A SimpleShell Implementation
## Introduction :wave:

TERM_ES is a command that reads lines from either a file or
the terminal, interprets them, and generally executes other commands.
It is the program that is running when a user logs into the system. TERM_ES implements a language that has flow control constructs, a macro facility that provides a variety of features in addition to data storage, along with history and line editing capabilities. It incorporates many features to aid interactive use and has the advantage that the interpretative language is common to both interactive and non-interactive use (shell scripts). That is, commands can be typed directly to the running shell or can be put into a file and the file can be executed directly by TERM_ES.

## Description :writing_hand:
This program simulates a command interpreter based in UNIX and GNU/LINUX with its basic commands. TERM_ES is both an interactive command language and a scripting language. TERM_ES is used by the operating system to control the execution of the system using shell scripts. TERM_ES is not supposed to be an exact implementation of shell, but can work with all basic functions.

## Features :pushpin:

- This program displays a prompt and waits for the user to type a command. A command line always ends with a new line (when the user presses ENTER key).

- The prompt is displayed again each time a command has been executed.

- When the user enters exit, TERM_ES will end and returns the status 0.

- The user could stop the program using Ctrl+D (END OF FILE).

- The shell handles command lines with arguments and pathways.

- The program does not quit when the user inputs ^C (Ctrl+C).

- The program prints the current environment when the user types env.

- This program executes the most common shell commands included with arguments.

- If a command cannot be found, It prints an error message and display the prompt again.

- This shell does not support wildcard characters such as ls *.c in parameters (or commands) at this time. 

- This shell doesn't support logical operators at this time.

## Command/Output examples :dart:

##### ls - Function that lists all files in current working directory.
```
# ls
AUTHORS         cool.Intro    getenvY.c           memCalcPATH.c  signalThing.c
builtIn.c       deColon.c     goFission.c         obtainPath.c   slashCMD.c
builtIn_cd.c    emptyInput.c  hsh                 parseInput.c   spoon.c
builtIn_env.c   eX127.c       intro               querY.c        str_concat.c
builtIn_exit.c  forkExec.c    lePrompt.c          README.md      term-es.c
_calloc.c       freeThings.c  man_1_simple_shell  shell.h        test
#
```
##### ps - Function that takes a snapshot of the current processes.
```
# ps  
  PID TTY          TIME CMD
19865 pts/23   00:00:00 bash
29403 pts/23   00:00:00 hsh
29573 pts/23   00:00:00 ps
#
```
##### cat - Function that concatenates files and prints on the standard output.
```
# cat goFission.c
#include "shell.h"

/**
 * goFission - splits/tokenizes input string per delimiter(s)
 * @input: input
 * @delim: delimiter(s) by which input is to be divided
 * Return: tokenized segment from input string, NULL otherwise
 */

char *goFission(char **input, char *delim)
{
        char *cmdT = NULL;

        while ((cmdT = strsep(input, delim)) && !*cmdT)
                ;

        return (cmdT);
}
# 
```
##### cd - Function that changes the working directory.
```
# ls
addHistory.c                           holbertonschool-zero_day  push
Betty                                  home                      root
bin                                    lib                       run
boot                                   lib32                     sbin
dev                                    lib64                     srv
etc                                    libx32                    sys
EXAMPLE.md                             man_1_simple_shell        tmp
holbertonschool-low_level_programming  media                     usr
holbertonschool-printf                 mnt                       var
holbertonschool-shell                  opt
holbertonschool-simple_shell           proc
# cd /holbertonschool-simple_shell
# ls
AUTHORS         cool.Intro    getenvY.c           memCalcPATH.c  signalThing.c
builtIn.c       deColon.c     goFission.c         obtainPath.c   slashCMD.c
builtIn_cd.c    emptyInput.c  hsh                 parseInput.c   spoon.c
builtIn_env.c   eX127.c       intro               querY.c        str_concat.c
builtIn_exit.c  forkExec.c    lePrompt.c          README.md      term-es.c
_calloc.c       freeThings.c  man_1_simple_shell  shell.h        test
#      
```

##### echo - Built in function that displays a line of text to standard output.
```
# echo Hey! Thanks for visiting our repository!
Hey! Thanks for visiting our repository!
# 
```
## TERM_ES accepts commands with options! :tada:

#### For this example, we will use the command 'ls' and the option '-l'.
```
# ls -l
total 340
-rw-r--r-- 1 root root    119 Aug  1 12:40 AUTHORS
-rw-r--r-- 1 root root    839 Aug  4 06:11 builtIn.c
-rw-r--r-- 1 root root    748 Aug  5 04:53 builtIn_cd.c
-rw-r--r-- 1 root root    449 Aug  3 20:42 builtIn_env.c
-rw-r--r-- 1 root root    865 Aug  5 04:53 builtIn_exit.c
-rw-r--r-- 1 root root    585 Aug  3 20:42 _calloc.c
-rw-r--r-- 1 root root    748 Aug  4 06:11 cool.Intro
-rw-r--r-- 1 root root    641 Aug  3 20:42 deColon.c
-rw-r--r-- 1 root root    431 Aug  1 23:18 emptyInput.c
-rw-r--r-- 1 root root    485 Aug  5 01:05 eX127.c
-rw-r--r-- 1 root root    521 Aug  5 01:05 eX13.c
-rw-r--r-- 1 root root    753 Aug  5 01:05 forkExec.c
-rw-r--r-- 1 root root    265 Aug  1 23:18 freeThings.c
-rw-r--r-- 1 root root   1184 Aug  5 01:05 getenvY.c
-rw-r--r-- 1 root root    363 Aug  1 23:18 goFission.c
. . .
# 
```
#### For this example, we'll use the 'cal' function (which prints a calendar to standard output) and we'll use the '-3' option.
```
# cal -3
                            2023
        July                 August              September
Su Mo Tu We Th Fr Sa  Su Mo Tu We Th Fr Sa  Su Mo Tu We Th Fr Sa
                   1         1  2  3  4  5                  1  2
 2  3  4  5  6  7  8   6  7  8  9 10 11 12   3  4  5  6  7  8  9
 9 10 11 12 13 14 15  13 14 15 16 17 18 19  10 11 12 13 14 15 16
16 17 18 19 20 21 22  20 21 22 23 24 25 26  17 18 19 20 21 22 23
23 24 25 26 27 28 29  27 28 29 30 31        24 25 26 27 28 29 30
30 31
# 
```
## Created/used functions :blue_book:
- `addHistory` - Stores all inputs from stdin to a list.
- `_atoi` - Converts string to integer.
- `builtIn` - Manages built-in functions & calls them upon matching input.
- `builtIn_cd` - Changes current working directory.
- `builtIn_env` - Prints environmental variables.
- `builtIn_exit` - Built-in provision for terminal exit upon command.
- `_calloc` - Allocs/initializes to 0, mem for array of objects of spec size.
- `deColon` - Divides input string into several based on colons present.
- `emptyInput` - Scans if input contains only whitespaces.
- `eX127` - Prints error message to stderr for exit code 127.
- `eX13` - Prints error message to stderr for exit code 13.
- `forkExec` - Launches input command with its arguments.
- `freecmdS` - Frees memory related to 'cmdS' in main.
- `getenvY` - Custom getenv function.
- `goFission` - Splits/tokenizes input string per delimiter(s).
- `hacK` - Checks status of PATH & PWD environmental variables.
- `lePrompt` - Gets line from input and maintains prompt.
- `memCalcPATH` - Calculates memory to be allocated when handling PATH.
- `obtainPath` - Processes PATH environmental variable for stat/access.
- `parseInput` - Parses/tokenizes input into string vector.
- `querY` - Checks if targeted file exists.
- `signalThing` - Defines behavior upon SIGINT, to be fed to signal.
- `slashCMD` - Concatenates slash + command to all strings in a vector.
- `spoon` - Manages cmd, filters by builtIn/access, then forkExecs or returns error.
- `str_concat` - Concatenates two given strings.

## Existing functons used :scroll:
- `access` - Check user's permissions for a file.
- `chdir` - Change working directory.
- `execve` - Execute program.
- `exit` - Cause the shell to exit.
- `_exit` - Terminate the calling process.
- `fflush` - Flush a stream.
- `fork` - Create a child process.
- `fprintf` - Function shall place output on the named output stream.
- `free` - Display amount of free and used memory in the system.
- `getline` - Deliminated string input.

## FLOWCHART :chart_with_upwards_trend:
![image](https://github.com/O-01/holbertonschool-simple_shell/assets/126730794/589cd272-daba-4e13-b833-eae607e30767)

##

## Compilation :hammer_and_wrench:
### ***TERM_ES*** was programmed on a Ubuntu 20.04 LTS platform and may be compiled
### using the following gcc options:
`# gcc -Wall -Werror -Wextra -pedantic -std=gnu89 -ggdb3 *.c -o hsh`
### The program may be launched using the following command:
`# ./hsh`

## Authors/Contact info :phone: :mailbox:
* **Eric Dzyk** **|** [Github](https://github.com/ericpo1sh) **|** [LinkedIn](https://linkedin.com/in/eric-dzyk-1b8976213) **|** [Email](mailto:ericpo1sh@gmail.com)  
* **Sammy Ansari** **|** [Github](https://github.com/O-01) **|** [LinkedIn](https://linkedin.com/sammy) **|** [Email](mailto:na.01goli@gmail.com)
##
![Holberton School - School of Computer Science and Programming](https://uploads-ssl.webflow.com/6105315644a26f77912a1ada/63eea844ae4e3022154e2878_Holberton.png)
##

```
# exit
OK BYE BYE!
```
