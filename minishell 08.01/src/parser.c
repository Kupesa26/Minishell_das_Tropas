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

void	ft_free_array(char **array)
{
	int	i;

	i = 0;
	if (!array)
		return ;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

void	parse_and_execute(char *line)
{
	char	**args;

	args = smart_split(line);
	if (!args)
		return ;
	if (args[0] == NULL)
	{
		ft_free_array(args);
		return ;
	}
    // Verificar comandos built-in
	if (strcmp(args[0], "cd") == 0)
		ft_cd(args);
	else if (strcmp(args[0], "echo") == 0)
		ft_echo(args);
	else if (strcmp(args[0], "export") == 0)
    		ft_export(args);
	else if (strcmp(args[0], "env") == 0)
		ft_env();
    	else if (strcmp(args[0], "pwd") == 0)
        	ft_pwd();
	else if (strcmp(args[0], "exit") == 0)
		ft_exit(args);
    	else
        	execute_command(args); // Outros comandos
	ft_free_array(args);
}
