/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviana-v <mviana-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 15:35:23 by mviana-v          #+#    #+#             */
/*   Updated: 2025/03/11 20:21:08 by mviana-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdio.h>
# include <stdbool.h>
# include <sys/wait.h>
# include <fcntl.h>
# include "./libft/libft.h"

typedef struct s_pipex
{
	bool	first_child;
	char	**path;
	char	**cmd1;
	char	**cmd2;
	int		fd_in;
	int		fd_out;
	int		fd[2];
}	t_pipex;

void	child_process(t_pipex *data_struct);
void	parent_process(t_pipex *data_struct);
char	**path_finder(char **env);

#endif
