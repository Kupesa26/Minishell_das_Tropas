/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_checks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efaustin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:10:29 by efaustin          #+#    #+#             */
/*   Updated: 2025/01/17 13:50:32 by antonfer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*process_brackets(char *line, char brackets, char *condition_char)
{
	if (line[0] != 'E')
	{
		if (condition_char)
			return (line + 1);
		return (line);
	}
	if (brackets != 'E')
	{
		if (*condition_char == '{')
			return (condition_char);
	}
	return (0);
}

char	*fetch_env(char *line, t_shell **shell, char *free_env)
{
	int		len;
	char	brackets;
	char	*parameter;
	char	*env_str;

	brackets = 0;
	brackets = (process_brackets("E", brackets, line))[0];
	line = process_brackets(line, 'E', &brackets);
	len = 0;
	if (line[len] == '?' && !free_env)
		return ("?");
	if (line[len] == '?')
	{
		if (brackets && line[len + 1] != '}')
			return (NULL);
		*free_env = 1;
		return (ft_itoa_base((*shell)->status, 10));
	}
	parameter = check_env_literal(shell, line, &len, brackets);
	if ((*shell)->current_status != SUCCESS)
		return (NULL);
	env_str = check_env_str(line, len, (*shell)->envp_cpy, brackets);
	if (env_str)
		return (env_str);
	return (parameter);
}

char	*check_env_literal(t_shell **shell, char *line, int *len,
		char brackets)
{
	char	*parameter;

	parameter = "";
	while (line[*len] && !ft_strchr(" \t$}", line[*len]))
	{
		if (line[*len] == '?')
			parameter = line + *len + 1;
		if (brackets && !parameter && (line[*len] == brackets
				|| ft_strchr("\'\"\\/", line[*len])))
		{
			error_handler(shell, NULL, BAD_SUBSTITUTION, ERR_BAD_SUB);
			return (parameter);
		}
		(*len)++;
	}
	if (brackets && (line[*len] == '$' || (line[*len] != '}' || !(*len))))
	{
		error_handler(shell, NULL, BAD_SUBSTITUTION, ERR_BAD_SUB);
		return (parameter);
	}
	line[*len] = line[*len];
	if (brackets)
		line[*len] = '\0';
	return (parameter);
}

char	*check_env_str(char *line, int len, char **envp, int brackets)
{
	int	env;

	env = 0;
	while (envp[env])
	{
		if (match_env(envp[env], line))
		{
			if (brackets == 1)
				line[len] = '}';
			return (envp[env] + len + 1);
		}
		env++;
	}
	if (brackets == -1)
		return (NULL);
	line[len] = line[len];
	if (brackets)
		line[len] = '}';
	return (NULL);
}

void	check_return_value(char **env_str, char *free_env, int return_value)
{
	if (match_str(*env_str, "?", 1))
	{
		*free_env = 1;
		*env_str = ft_itoa_base(return_value, 10);
	}
}
