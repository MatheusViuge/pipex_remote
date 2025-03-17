/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviana-v <mviana-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 19:10:25 by mviana-v          #+#    #+#             */
/*   Updated: 2025/03/17 19:54:35 by mviana-v         ###   ########.fr       */
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
