/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviana-v <mviana-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 17:26:11 by mviana-v          #+#    #+#             */
/*   Updated: 2025/03/07 17:33:09 by mviana-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_process(int *fd, int ac, char **av, char **env)
{
	(void)fd;
	(void)ac;
	(void)av;
	(void)env;
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

void	parent_process(int *fd, int ac, char **av, char **env, int pid)
{
	(void)fd;
	(void)ac;
	(void)av;
	(void)env;
	(void)pid;
	printf("pid from parent %d\n", getpid());
	printf("hello world from parent\n");
	exit(0);
	// close(fd[1]);
	// dup2(fd[0], 0);
	// close(fd[0]);
	// execve(av[3], &av[3], env);
	// perror("execve");
	// exit(1);
}