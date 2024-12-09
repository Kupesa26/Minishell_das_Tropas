/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_handlers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akupesa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 20:23:02 by akupesa           #+#    #+#             */
/*   Updated: 2024/12/07 20:23:05 by akupesa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdio.h>
#include <stdlib.h>

int	ft_echo(char **args)
{
	int	i;
	int	newline;

	i = 1;
	newline = 1;

	if (args[1] && strcmp(args[1], "-n") == 0 && args[i][2] == '\0')
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
	{
		printf ("\n");
	}
	return (0);
}

int	ft_cd(char *address)
{
	
}