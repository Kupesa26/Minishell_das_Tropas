#ifndef MINISHELL_H
#define MINISHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void minishell_loop(void);
void parse_and_execute(char *line);
void execute_command(char **args);

#endif
