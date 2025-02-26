/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_sign_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efaustin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 16:10:29 by efaustin          #+#    #+#             */
/*   Updated: 2025/01/22 16:27:00 by efaustin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

bool	ft_is_end_of_var(char *matrix, int block_flag, int inside_quotes, int j)
{
	char	c;

	c = matrix[j + 1];
	if ((matrix[j] == '$' && (matrix[j + 1] == '$' || matrix[j + 1] == '\0')
			&& block_flag == 0) || (matrix[j] == '$' && (matrix[j + 1] == '\''
				|| matrix[j + 1] == '\"') && (block_flag == 1 || inside_quotes
				% 2 == 1)))
		return (true);
	if (block_flag == 0 || inside_quotes % 2 == 0)
		if (c == ' ' || c == '\0' || c == '$' || c == '\\' || c == '|'
			|| c == '>' || c == '<' || c == ';' || c == '&' || c == '`'
			|| c == '\t' || c == '\n' || c == '\r' || c == '\v' || c == '\f'
			|| c == '*' || c == '[' || c == ']' || c == '{' || c == '}'
			|| c == '~' || c == '#' || c == '%' || c == '!' || c == '@'
			|| c == '^' || c == '=' || c == '+' || c == '-' || c == '.'
			|| c == ',' || c == ':' || c == ';' || c == '&' || c == '/')
			return (true);
	return (false);
}

void	ft_quotes_block_toggle(char c, int *block_flag, int *inside_quotes)
{
	if (c == '\"' && *block_flag == 0)
		*inside_quotes += 1;
	if (c == '\'' && *block_flag == 1 && *inside_quotes % 2 != 1)
		*block_flag = 0;
	else if (c == '\'' && *block_flag == 0 && *inside_quotes % 2 != 1)
		*block_flag = 1;
}

void	ft_switch_flags(int *block_flag)
{
	if (*block_flag == 0)
		*block_flag = 1;
	else if (*block_flag == 1)
		*block_flag = 0;
}

char	*ft_strchr_validenv(const char *s)
{
	int	s_len;

	if (s == NULL)
		return (NULL);
	if (ft_isdigit((s[0])) == 1 || s[0] == '\"' || s[0] == '\'')
		return ((char *)(s + 1));
	if (ft_isalpha((s[0]) == 0 && s[0] != '_'))
		return ((char *)s);
	s_len = ft_strlen(s);
	while (s_len >= 0 && *s != '=')
	{
		if (*s == '\"' || *s == '\'' || (ft_isalnum(*s) != 1 && *s != '_'))
			return ((char *)s);
		s++;
		s_len--;
	}
	return ((char *)s);
}

char	*ft_putstr_instr(char *str, char *insert_str, int insert_len,
		int insert_index)
{
	char	*new_str;
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	new_str = (char *)ft_calloc(ft_strlen(str) + ft_strlen(insert_str) + 1,
			sizeof(char));
	while (str[k] != '\0')
	{
		if (i == insert_index)
			k += insert_len;
		if (i == insert_index)
			while (insert_str != NULL && insert_str[j] != '\0')
				new_str[i++] = insert_str[j++];
		if (str[k] != '\0')
			new_str[i++] = str[k++];
	}
	if (str != NULL)
		free(str);
	return (new_str);
}
