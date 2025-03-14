/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviana-v <mviana-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 17:26:11 by mviana-v          #+#    #+#             */
/*   Updated: 2025/03/14 16:01:31 by mviana-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	path_join(char **path, char *str)
{
	int		i;
	char	*tmp;

	i = 0;
	while (path[i])
	{
		tmp = ft_strjoin(path[i], str);
		if (!tmp)
		{
			error_handler("ft_strjoin", NULL);
			return ;
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
				error_handler("ft_split", NULL);
			path_join(path, "/");
			return (path);
		}
		i++;
	}
	error_handler("PATH not found", NULL);
	return (NULL);
}

void	daycare(t_pipex *data_struct)
{
	(void)data_struct;
	printf("pid from child %d\n", getpid());
	printf("hello world from child\n");
	data_killer(data_struct);
	exit(0);
}

void	error_handler(char *message, t_pipex *data)

{
	if (data)
		data_killer(data);
	perror(message);
	exit(1);
};

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
