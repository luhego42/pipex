#include "pipex.h"

void    child(int *pipe, char **argv, char **env)
{
	int fd;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		exit(0);
	dup2(fd, STDIN_FILENO);
	dup2(pipe[1], STDOUT_FILENO);
	close(pipe[0]);
	exec_cmd(argv[2], env);
}

void    parent(int *pipe, char **argv, char **env)
{
	int fd_outfile;

	fd_outfile = open(argv[4], O_WRONLY | O_CREAT, 00644);
	if (fd_outfile == -1)
		exit(0);
	dup2(pipe[0], STDIN_FILENO);
	dup2(fd_outfile, STDOUT_FILENO);
	close(pipe[1]);
	exec_cmd(argv[3], env);
}

int main(int argc, char **argv, char **env)
{
	int     p[2];
	pid_t   pid;

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

/*
	int fd[2]
	fd[0] = open(argv[1], O_RDONLY);
	fd[1] = -1;
	if (fd[0] == -1)
		perror(argv[1]);
	if (pipe(p1) == -1)
	{
		write(1, "pipe, error\n", 12);
		exit(0);
	}
	else
	{
		pid = exec_cmd(argv[2], env, fd, p1);
		//waitpid(pid, 0, 0);
	}
	fd[0] = (open(argv[4], O_WRONLY | O_CREAT, S_IRWXU));
	if (file[0] == -1)
		perror(argv[4]);
	pid = exec_cmd(argv[3], env, p1, fd);
 	//waitpid(pid, 0, 0); */
	return (0);
}
