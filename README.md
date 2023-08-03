# *TERM_ES* - `A SimpleShell Implementation`
## Introduction :wave:

TERM_ES is a command that reads lines from either a file or
the terminal, interprets them, and generally executes other commands.
It is the program that is running when a user logs into the system. TERM_ES implements a language that has flow control constructs, a macro facility that provides a variety of features in addition to data storage, along with history and line editing capabilities. It incorporates many features to aid interactive use and has the advantage that the interpretative language is common to both interactive and non-interactive use (shell scripts).  That is, commands can be typed directly to the running shell or can be put into a file and the file can be executed directly by TERM_ES.

## Description :writing_hand:
This program simulates a command interpreter based in Unix and GNU/LINUX with its basic commands. TERM_ES is both an interactive command language and a scripting language. TERM_ES is used by the operating system to control the execution of the system using shell scripts. TERM_ES is not supposed to be an exact implementation of powershell, but can work with all basic functions.

## Features :pushpin:

- This program displays a prompt and wait for the user to type a command. A command line always ends with a new line (when the user push ENTER key).

- The prompt is displayed again each time a command has been executed.
- When the user enters exit, TERM_ES will end and returns the status 0.
- The user could stop the program using Ctrl+D (end of file).

- The shell handles command lines with arguments and pathways.

- The program does not quit when the user inputs ^C (Ctrl+C).

- The program prints the current environment when the user types env.

- This program executes the most common shell commands included with arguments.

- If an command cannot be found, It prints an error message and display the prompt again.

- This Shell does not support wildcard characters such as ls *.c in parameters (or commands). 

- This shell does support pipes, but doesn't support logical operators.

## Commands/Outputs examples :dart:

##### ls - Function that lists all files in current working directory.
```
# ls
AUTHORS   builtIn_env.c   emptyInput.c   forkExec.c   goFission.c   intro   
man_1_simple_shell   README.md  signalThing.c   test   builtIn_cd.c   cool.Intro 
fileExist.c freeThings.c   hsh   lePrompt.c   parseInput.c   shell.h   TERM_ES.c
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
##### cat - Function that concatenates files and print on the standard output.
```
# cat goFission.c
#include "shell.h"

/**
 * goFission - splits/tokenizes input string per delimiter(s)
 * @input: input
 * @delim: delimiter(s) by which input is to be divided
 * Return: next acceptable instance of input, NULL otherwise
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
total 208
-rw-r--r-- 1 root root    119 Aug  2 09:51 AUTHORS
-rw-r--r-- 1 root root    331 Aug  2 09:51 builtIn_cd.c
-rw-r--r-- 1 root root    290 Aug  2 09:51 builtIn_env.c
-rw-r--r-- 1 root root    658 Aug  2 09:51 cool.Intro
-rw-r--r-- 1 root root    431 Aug  2 09:51 emptyInput.c
-rw-r--r-- 1 root root    235 Aug  2 09:51 fileExist.c
-rw-r--r-- 1 root root    437 Aug  2 09:51 forkExec.c
-rw-r--r-- 1 root root    265 Aug  2 09:51 freeThings.c
-rw-r--r-- 1 root root    363 Aug  2 09:51 goFission.c
-rwxr-xr-x 1 root root 134936 Aug  2 09:51 hsh
-rw-r--r-- 1 root root   7002 Aug  2 09:51 intro
-rw-r--r-- 1 root root    561 Aug  2 09:51 lePrompt.c
-rw-r--r-- 1 root root   4078 Aug  2 09:51 man_1_simple_shell
-rw-r--r-- 1 root root    679 Aug  2 09:51 parseInput.c
-rw-r--r-- 1 root root     33 Aug  2 09:51 README.md
-rw-r--r-- 1 root root   1069 Aug  2 09:51 shell.h
-rw-r--r-- 1 root root    244 Aug  2 09:51 signalThing.c
-rw-r--r-- 1 root root    631 Aug  2 09:51 term-es.c
-rwxr-xr-x 1 root root     77 Aug  2 09:51 test
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

- `builtIn_env` - Prints environmental variables.
- `emptyInput` - Scans if input contains only whitespaces.
- `forkExec` - Launches input command with its arguments.
- `goFission` - Splits/tokenizes input string per delimiter(s).
- `signalThing` - Checks for EOF/SIGINT and exits terminal.
- `builtIn_cd` - Changes current working directory.
- `fileExist` - Checks if targeted file exists.
- `freecmdS` - Frees memory related to 'cmdS' in main.
- `lePrompt` - Gets line from input and maintains prompt.
- `parseInput` - Parses/tokenizes input into string vector.
- `obtainPath` - Processes PATH env variable for stat/access.
- `str_concat` - Concatenates two given strings.
- `addHistory` - Stores all inputs from stdin to a list.

## FLOWCHART :chart_with_upwards_trend:
PLACEHOLDER FOR FUTURE FLOWCHART

## Compilation :hammer_and_wrench:
### ***TERM_ES*** was programmed on `Ubuntu 20.04 LTS` machine using gcc options:
`gcc -Wall -Werror -Wextra -pedantic -std=gnu89 -ggdb3 *.c -o hsh`

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
