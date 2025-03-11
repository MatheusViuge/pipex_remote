/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviana-v <mviana-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 17:26:11 by mviana-v          #+#    #+#             */
/*   Updated: 2025/03/11 20:25:43 by mviana-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**path_finder(char **env)
{
	char	**path;
	int		i;

	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
		{
			path = ft_split(env[i] + 5, ':');
			if (!path)
			{
				perror("ft_split");
				exit(1);
			}
			return (path);
		}
		i++;
	}
	return (NULL);
}

void	child_process(t_pipex *data_struct)
{
	(void)data_struct;
	printf("pid from child %d\n", getpid());
	printf("hello world from child\n");
	exit(0);
	// close(fd[0]);
	// dup2(fd[1], 1);
	// close(fd[1]);
	// execve(av[2], &av[2], env);
	// perror("execve");
	// exit(1);
}

void	parent_process(t_pipex *data_struct)
{
	(void)data_struct;
	printf("pid from parent %d\n", getpid());
	printf("hello world from parent\n");
	printf("Now printing path\n");
	for (int i = 0; data_struct->path[i]; i++)
		printf("%s\n", data_struct->path[i]);
	exit(0);
	// close(fd[1]);
	// dup2(fd[0], 0);
	// close(fd[0]);
	// execve(av[3], &av[3], env);
	// perror("execve");
	// exit(1);
}