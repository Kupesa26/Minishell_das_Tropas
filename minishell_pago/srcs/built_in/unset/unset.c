/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efaustin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:10:29 by efaustin          #+#    #+#             */
/*   Updated: 2025/01/10 15:13:02 by efaustin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */




#include "minishell.h"

/*
**	Flags error if option found.
**	If env is not found, it isn't considered an error.
*/

void	built_in_unset(t_shell **shell)
{
	t_list	*arg;

	arg = (*((*shell)->current_command))->args->next;
	if (arg && *(arg->name) == '-')
	{
		error_handler(shell, arg->name, ERROR, ERR_NO_OPT);
		return ;
	}
	while (arg)
	{
		pop_env(shell, arg->name);
		arg = arg->next;
	}
}
