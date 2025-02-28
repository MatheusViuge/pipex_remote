/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviana-v <mviana-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 15:33:26 by mviana-v          #+#    #+#             */
/*   Updated: 2025/02/27 23:50:55 by mviana-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	pipex( int ac, char **av, char **env)
{
	int	pid;
	int	fd[2];


	pid = fork();
	if (pid == 0)
		child_process(fd, av, env);
	else if (pid == -1)
	{
		strerror("fork");
		exit (1);
	}
	waitpid(pid, NULL, 0);
}

static int	here_doc(void)
{
	ft_putendl_fd("here_doc not implemented", 1);
	return (1);
}

int	main(int ac, char **av, char **env)
{
	if (ac != 5)
	{
		ft_putstr_fd("Error: Wrong number of arguments\n", 2);
		return (1);
	}
	else if (ft_strncmp(av[1], "here_doc", 9) == 0)
		if (here_doc())
			return (1);
	else
		pipex(ac, av, env);
	return (0);
}
