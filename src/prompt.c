/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonfer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 08:30:43 by antonfer          #+#    #+#             */
/*   Updated: 2024/11/27 08:33:33 by antonfer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	minishell_loop(void)
{
	char	*line;
	size_t	len;

	len = 0;
	line = NULL;
	while (1)
	{
		printf("minishell> ");
		if (getline(&line, &len, stdin) == -1)
			break;
		if (strcmp(line, "exit\n") == 0)
			break;
		parse_and_execute(line);
	}
	free(line);
}