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

void	minishell_loop(void);
char	*command_generator(const char *text, int state);
void	initialize_completion(void);
void	parse_and_execute(char *line);
void	execute_command(char **args);
void	ft_cd(char **args);
void	ft_exit(char **args);
void	ft_pwd(void);
void	ft_echo(char **args);
void	ft_env(void);
void	ft_export(char **args);


#endif