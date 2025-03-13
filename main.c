/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviana-v <mviana-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 15:33:26 by mviana-v          #+#    #+#             */
/*   Updated: 2025/03/13 17:50:56 by mviana-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	pipex(t_pipex *data_center)
{
	int	pid;

	pid = fork();
	if (pid == 0)
	{
		daycare(data_center);
	}
	else if (pid == -1)
	{
		perror("fork");
		exit (1);
	}
	waitpid(pid, NULL, 0);
	finish_process(data_center);
}

static void	free_splits(char **tab)
{
	int	i;

	i = 0;
	if (!tab)
		return ;
	while (tab[i])
	{
		if (tab[i])
			free(tab[i]);
		i++;
	}
	free(tab);
}

void	data_killer(t_pipex *data)
{
	if (data->path)
		free_splits(data->path);
	if (data->cmd1)
		free_splits(data->cmd1);
	if (data->cmd2)
		free_splits(data->cmd2);
	if (data->fd_in >= 0)
		close(data->fd_in);
	if (data->fd_out >= 0)
		close(data->fd_out);
	free(data);
}

static t_pipex	*brain_init(char **av, char **env)
{
	t_pipex	*data;
	int		splits;

	data = (t_pipex *)ft_calloc(1, sizeof(t_pipex));
	data->fd_in = open(av[1], O_RDONLY);
	data->cmd1 = ft_split(av[2], ':');
	data->cmd2 = ft_split(av[3], ':');
	data->fd_out = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	data->path = path_finder(env);
	splits = (!data->cmd1 || !data->cmd2 || !data->path);
	if (data->fd_in < 0 || data->fd_out < 0 || splits)
	{
		data_killer(data);
		return (NULL);
	}
	return (data);
}

int	main(int ac, char **av, char **env)
{
	t_pipex	*brain;

	brain = brain_init(av, env);
	if (!brain)
	{
		perror("Structure initialization");
		return (1);
	}
	if (ac != 5)
	{
		ft_putendl_fd("Usage: ./pipex file1 cmd1 cmd2 file2", 2);
		return (1);
	}
	else if (ft_strncmp(av[1], "here_doc", 9) == 0)
	{
		ft_putendl_fd("here_doc not implemented", 2);
		return (1);
	}
	else
		pipex(brain);
	return (0);
}
