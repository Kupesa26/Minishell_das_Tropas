#ifndef MINISHELL_H
# define MINISHELL_H

# define PATH_MAX

# include <dirent.h>
# include <errno.h>
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "../libft/libft.h"

extern char	**commands;

void	ft_pwd(void);
void	ft_env(void);
void	cleanup(void);
void	ft_cd(char **args);
void	minishell_loop(void);
void	ft_exit(char **args);
void	ft_echo(char **args);
void	ft_export(char **args);
char	**smart_split(char *line);
void	ft_free_array(char **array);
void	execute_command(char **args);
void	parse_and_execute(char *line);
char	*command_generator(const char *text, int state);
char	**command_completion(const char *text, int start, int end);

#endif