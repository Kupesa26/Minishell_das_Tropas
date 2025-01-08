/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonfer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 08:29:07 by antonfer          #+#    #+#             */
/*   Updated: 2024/11/27 08:29:22 by antonfer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**commands = NULL;

int main(void)
{

	char	*result = command_generator("src", 0);

	minishell_loop();
	if (result)
		printf("Generated command: %s\n", result);
	else
		printf("No command generated.\n");
	return (0);
}