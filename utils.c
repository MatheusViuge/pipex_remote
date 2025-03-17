/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviana-v <mviana-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 17:26:11 by mviana-v          #+#    #+#             */
/*   Updated: 2025/03/17 20:22:56 by mviana-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void playground(t_pipex *data)
{
	int	i;
	char	**cmd;

	i = 0;
	if (data->first_child)
	{
		path_join(data->path, data->cmd1[0]);
		cmd = data->cmd1;
	}
	else
	{
		path_join(data->path, data->cmd2[0]);
		cmd = data->cmd2;
	}
	while (access(data->path[i], F_OK) == -1)
	{
		i++;
		if (!*data->path[i])
			error_handler("command not found", data);
	}
	if (execve(data->path[i], cmd, NULL) == -1)
		error_handler("execve", data);
	data_killer(data);
	exit(0);
}

void	daycare(t_pipex *data)
{
	if (data->first_child)
	{
		close(data->fd[0]);
		dup2(data->fd_in, STDIN_FILENO);
		close(data->fd_in);
		dup2(data->fd[1], STDOUT_FILENO);
		close(data->fd[1]);
	} else
	{
		close(data->fd[1]);
		dup2(data->fd[0], STDIN_FILENO);
		close(data->fd[0]);
		dup2(data->fd_out, STDOUT_FILENO);
		close(data->fd_out);
	}
	playground(data);
	data_killer(data);
	exit(0);
}

void	error_handler(char *message, t_pipex *data)

{
	if (data)
		data_killer(data);
	perror(message);
	exit(1);
};

void	finish_process(t_pipex *data)
{
	printf("Process finished\n");
	data_killer(data);
	exit(0);
}
