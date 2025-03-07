/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviana-v <mviana-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 15:35:23 by mviana-v          #+#    #+#             */
/*   Updated: 2025/03/07 20:44:13 by mviana-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdio.h>
# include <stdbool.h>
# include <sys/wait.h>
# include "./libft/libft.h"

typedef struct s_pipex
{
	bool	first_child;
	int		fd_in;
	int		fd_out;
	int		fd[2];
}	t_pipex;

void	child_process(int *fd, int ac, char **av, char **env);
void	parent_process(int *fd, int ac, char **av, char **env, int pid);

#endif
