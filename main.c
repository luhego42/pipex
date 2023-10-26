/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luhego <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 15:25:44 by luhego            #+#    #+#             */
/*   Updated: 2023/10/26 15:57:31 by luhego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child(int *pipe, char **argv, char **env)
{
	int	fd;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		close(pipe[0]);
		close(pipe[1]);
		exit(0);
	}
	dup2(fd, STDIN_FILENO);
	dup2(pipe[1], STDOUT_FILENO);
	close(pipe[0]);
	exec_cmd(argv[2], env);
	close(fd);
	close(pipe[1]);
}

void	parent(int *pipe, char **argv, char **env)
{
	int	fd_outfile;

	fd_outfile = open(argv[4], O_WRONLY | O_CREAT, 00644);
	if (fd_outfile == -1)
	{
		close(pipe[0]);
		close(pipe[1]);
		exit(0);
	}
	dup2(pipe[0], STDIN_FILENO);
	dup2(fd_outfile, STDOUT_FILENO);
	close(pipe[1]);
	exec_cmd(argv[3], env);
	close(fd_outfile);
	close(pipe[0]);
}

int	main(int argc, char **argv, char **env)
{
	int		p[2];
	pid_t	pid;

	if (argc == 5)
	{
		if (pipe(p) == -1)
		{
			write(1, "pipe, error\n", 12);
			exit(0);
		}
		pid = fork();
		if (pid == 0)
			child(p, argv, env);
		waitpid(pid, 0, 0);
		parent(p, argv, env);
	}
	else
		ft_putstr_fd("Error, entry must be like : file1 cmd1 cmd2 file2\n", 2);
	return (0);
}
