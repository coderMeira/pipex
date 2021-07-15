#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<string.h>
#include<sys/wait.h>
#include "../lib/libft/inc/libft.h"

static void	child(char **av, int *fd, pid_t pid)
{
	dup2(fd[1], 1);
	close(fd[1]);
	close(fd[0]);
	execlp("ls", "ls", NULL);
}

static void	father(char **av, int *fd, pid_t pid)
{
	dup2(fd[0], 0);
	close(fd[1]);
	close(fd[0]);
	execlp("cat", "cat", NULL);
}

int	main(int ac, char **av)
{
	int		fd[2];
	pid_t	pid;

	if (ac != 5)
	{
		ft_putstr_fd("Usage : ./pipex infile cmd1 cmd2 outfile\n", 2);
		return(0);
	}
	if ((pipe(fd) == -1))
	{
		perror("pipe error");
		exit(-1);
	}
	pid = fork();
	if (pid == -1)
	{
		perror("fork error");
		exit(1);
	}
	else if (pid == 0)
		child(av, fd, pid);
	else
		father(av, fd, pid);
	wait(NULL);
	return (0);
}
