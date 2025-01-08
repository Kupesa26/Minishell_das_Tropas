#include "minishell.h"

void	remove_quotes_improv(char *str)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\'')
		{
			i++; 
			continue ;
		}
		str[j++] = str[i++];
	}
	str[j] = 0;
}

char	**smart_split(char *line)
{
	int		i;
	int		quotes;
	char	**args;
	char	*trimmed;

	trimmed = ft_strtrim(line, " \t\n\r");
	if (!trimmed)
		return (NULL);
	i = -1;
	quotes = 0;
	while (trimmed[++i] != '\0')
	{
		if (trimmed[i] == ' ' && quotes % 2 != 1)
			trimmed[i] = -32;
		if (trimmed[i] == '\'')
			quotes++;
	}
	remove_quotes_improv(trimmed);
	args = ft_split(trimmed, -32);
	free(trimmed);
	if (!args)
		return (NULL);
	return (args);
}