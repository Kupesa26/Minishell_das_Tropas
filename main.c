/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akupesa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 11:30:13 by akupesa           #+#    #+#             */
/*   Updated: 2024/12/06 11:30:27 by akupesa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int	main(void)
{
	int		status;
	pid_t	pid;

	printf("Minishell: Iniciando execução...\n");
	pid = fork();
	if (pid < 0)
	{
		perror("Erro ao criar o processo");
		exit(EXIT_FAILURE);
	}
	if (pid == 0)
	{
		char	*command = "/bin/ls";
		char	*args[] = { "ls", "-l", NULL };
		printf("Minishell: Processo filho executando '%s'...\n", command);
		execve(command, args, NULL);
		perror("Erro ao executar o comando");
		exit(EXIT_FAILURE);
	}
	else
	{
		printf ("Minishell: Processo pai aguardando o filho...\n");
		waitpid(pid, &status, 0);
		if (WIFEXITED(status))
		{
			printf("Minishell: Filho terminou com status %d\n", WEXITSTATUS(status));
		}
		else
		{
			printf("Minishell: Filho terminou de forma anormal.\n");
		}
	}
	printf("Minishell: Execução concluída.\n");
	return (0);
}

