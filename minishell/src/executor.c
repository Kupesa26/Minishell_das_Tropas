/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonfer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 08:28:20 by antonfer          #+#    #+#             */
/*   Updated: 2024/11/27 08:28:57 by antonfer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	execute_command(char **args)
{
	if (fork() == 0)
	{
		execvp(args[0], args);
		perror("execvp failed");
		exit(1);
	}
	else
	{
		wait(NULL);
	}
}

void handle_cd(char **args)
{
    if (args[1] == NULL) // Sem argumentos
    {
        printf("minishell: cd: expected argument\n");
    }
    else if (chdir(args[1]) != 0) // Mudar diretório
    {
        perror("minishell: cd");
    }
}

void handle_pwd(void)
{
    char cwd[1024];
    if (getcwd(cwd, sizeof(cwd)) != NULL)
    {
        printf("%s\n", cwd);
    }
    else
    {
        perror("minishell: pwd");
    }
}

void handle_exit(char **args)
{
    int exit_code = 0;
    if (args[1] != NULL) // Verificar argumento
    {
        exit_code = atoi(args[1]);
    }
    exit(exit_code);
}

void	handle_echo(char **args)
{
	int		i;
	int		newline;

	i = 1;
	newline = 1;

	if (args[i] && strcmp(args[i], "-n") == 0)
	{
		newline = 0;
		i++;
	}
	while (args[i])
	{
		printf("%s", args[i]);
		if (args[i + 1])
			printf(" ");
		i++;
	}
	if (newline)
		printf("\n");
}

void	handle_env(void)
{
	int		i;
	extern char		**environ;

	i = 0;
	while (environ[i])
	{
		printf("%s\n", environ[i]);
		i++;
	}
}

void handle_export(char **args)
{
    if (args[1] == NULL)
    {
        fprintf(stderr, "minishell: export: expected argument\n");
        return;
    }

    if (putenv(args[1]) != 0) // Formato esperado: VAR=value
    {
        perror("minishell: export");
    }
}