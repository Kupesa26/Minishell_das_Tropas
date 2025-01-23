/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_check_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efaustin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 16:10:29 by efaustin          #+#    #+#             */
/*   Updated: 2025/01/22 16:27:00 by efaustin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	toggle_quotes(int quotes)
{
	return (quotes * -1);
}

bool	handle_pipe(int *token)
{
	if (*token == 1)
		return (true);
	*token *= -1;
	return (false);
}

bool	handle_redirection(int *token, char *line, int *i)
{
	if (*token == 1)
		return (true);
	if (line[*i + 1] == '>')
		(*i)++;
	*token *= -1;
	return (false);
}

bool	handle_less_than(int *token, char *line, int *i)
{
	if (*token == 1)
		return (true);
	if (line[*i + 1] == '<')
		(*i)++;
	*token *= -1;
	return (false);
}

bool	handle_other_chars(char ch, int *token)
{
	if (ch != '|' && ch != '<' && ch != '>' && ch != ' ' && ch != '\t')
		*token = -1;
	return (false);
}
