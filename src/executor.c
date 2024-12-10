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