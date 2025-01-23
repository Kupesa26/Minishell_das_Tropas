/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_fd_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efaustin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 16:10:29 by efaustin          #+#    #+#             */
/*   Updated: 2025/01/22 16:27:00 by efaustin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	ft_init_fd(t_fd *fds)
{
	fds->fd_in = STDIN_FILENO;
	fds->fd_out = STDOUT_FILENO;
	fds->fd_heredoc = 0;
	fds->filename_in = NULL;
	fds->filename_out = NULL;
}

void	ft_reset_fd_out(t_fd *fds)
{
	if (fds->fd_out != STDOUT_FILENO)
	{
		close(fds->fd_out);
		fds->fd_out = STDOUT_FILENO;
	}
	if (fds->filename_out != NULL)
	{
		free(fds->filename_out);
		fds->filename_out = NULL;
	}
}

void	ft_reset_fd_in(t_fd *fds)
{
	if (fds->fd_heredoc == 1)
		fds->fd_heredoc = 0;
	if (fds->fd_in != STDIN_FILENO)
	{
		close(fds->fd_in);
		fds->fd_in = STDIN_FILENO;
	}
	if (fds->filename_in != NULL)
	{
		free(fds->filename_in);
		fds->filename_in = NULL;
	}
}

void	ft_reset_fd(t_fd *fds)
{
	if (fds->fd_in != STDIN_FILENO)
	{
		close(fds->fd_in);
		fds->fd_in = STDIN_FILENO;
	}
	if (fds->fd_out != STDOUT_FILENO)
	{
		close(fds->fd_out);
		fds->fd_out = STDOUT_FILENO;
	}
	if (fds->fd_heredoc == 1)
		fds->fd_heredoc = 0;
	if (fds->filename_in != NULL)
	{
		free(fds->filename_in);
		fds->filename_in = NULL;
	}
	if (fds->filename_out != NULL)
	{
		free(fds->filename_out);
		fds->filename_out = NULL;
	}
}
