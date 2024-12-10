/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonfer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 08:29:26 by antonfer          #+#    #+#             */
/*   Updated: 2024/11/27 08:30:39 by antonfer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	parse_and_execute(char *line)
{
	char *args[1000];
	int	i;
	char	*token;

	i = 0;
	token = strtok(line, " \n");
	while (token)
	{
		args[i++] = token;
		token = strtok(NULL, " \n");
	}
	args[i] = NULL;
	execute_command(args);
}