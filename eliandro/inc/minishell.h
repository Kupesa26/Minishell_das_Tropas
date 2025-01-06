#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/wait.h>

// Libs para histórico de comandos
# include <readline/readline.h>
# include <readline/history.h>
// Para acessar diretórios
#include <dirent.h> 

// Adicione a declaração no topo, junto com outras variáveis globais
extern char **commands;

// Funcs de completamento de comandos
char    **load_system_commands(void);
void    free_system_commands(void);
char    **command_completion(const char *text, int start, int end);
char    *command_generator(const char *text, int state);

void minishell_loop(void);
void parse_and_execute(char *line);
void execute_command(char **args);

#endif
