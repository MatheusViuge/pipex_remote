/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviana-v <mviana-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 17:26:11 by mviana-v          #+#    #+#             */
/*   Updated: 2025/03/13 17:47:55 by mviana-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	path_join(char **path)
{
	int		i;
	char	*tmp;

	i = 0;
	while (path[i])
	{
		tmp = ft_strjoin(path[i], "/");
		if (!tmp)
		{
			perror("ft_strjoin");
			exit(1);
		}
		free(path[i]);
		path[i] = tmp;
		i++;
	}
}

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
			path_join(path);
			return (path);
		}
		i++;
	}
	perror("PATH not found");
	exit(1);
}

void	daycare(t_pipex *data_struct)
{
	(void)data_struct;
	printf("pid from child %d\n", getpid());
	printf("hello world from child\n");
	data_killer(data_struct);
	exit(0);
}

void	finish_process(t_pipex *data_struct)
{
	(void)data_struct;
	printf("pid from parent %d\n", getpid());
	printf("hello world from parent\n");
	printf("Now printing path\n");
	for (int i = 0; data_struct->path[i]; i++)
		printf("%s\n", data_struct->path[i]);
	data_killer(data_struct);
	exit(0);
}
