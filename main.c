/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviana-v <mviana-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 15:33:26 by mviana-v          #+#    #+#             */
/*   Updated: 2025/03/11 20:20:23 by mviana-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	pipex(t_pipex *data_center)
{
	int	pid;
	
	pid = fork();
	if (pid == 0)
		child_process(data_center);
	else if (pid == -1)
	{
		perror("fork");
		exit (1);
	}
	waitpid(pid, NULL, 0);
	parent_process(data_center);
}

static void	ag_error(void)
{
	ft_putendl_fd("Usage: ./pipex file1 cmd1 cmd2 file2", 2);
}

int	main(int ac, char **av, char **env)
{
	t_pipex	*data_center;
	data_center = malloc(sizeof(t_pipex));
	data_center->path = path_finder(env);
	if (ac != 5)
	{
		ag_error();
		return (1);
	}
	else if (ft_strncmp(av[1], "here_doc", 9) == 0)
	{
		ft_putendl_fd("here_doc not implemented", 2);
		return (1);
	}
	else
		pipex(data_center);
	return (0);
}
