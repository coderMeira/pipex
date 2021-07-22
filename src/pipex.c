#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<string.h>
#include<sys/wait.h>
#include "../lib/libft/inc/libft.h"

static char **get_paths(char **env, char **cmd, int *i)
{
	char	*path;
	char	*tmp;
	char 	**varios;

	path = env[1] + 5;
	varios = ft_split(path, ':');
	while (varios[*i])
	{
		tmp = ft_strjoin(varios[*i], "/");
		varios[*i] = ft_strjoin(tmp, *cmd);
		free(tmp);
		(*i)++;
	}
	return (varios);
}

static void	child(int *fd, char **cmd1, char **env)
{
	char	**varios;
	int		i;

	varios = get_paths(env, cmd1, &i);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[1]);
	close(fd[0]);
	while (i--)
		execve(varios[i], cmd1, NULL);
}

static void	father(int *fd, char **cmd2, char **env, pid_t pid)
{
	char	**varios;
	int		i;

	varios = get_paths(env, cmd2, &i);
	waitpid(pid, NULL, 0);
	dup2(fd[1], STDIN_FILENO);
	while (i--)
		execve(varios[i], cmd2, NULL);
	close(fd[1]);
	close(fd[0]);
}

int	main(int ac, char **av, char **env)
{
	int		fd[2];
	pid_t	pid;
	char	**cmd1;
	char	**cmd2;

	cmd1 = ft_split(av[2], ' ');
	cmd2 = ft_split(av[3], ' ');

	// while (cmd1[j])
	// {
	// 	printf("cmd1[%d] = %s\n", j, cmd1[j]);
	// 	j++;
	// }
	// j = 0;
	// while (cmd2[j])
	// {
	// 	printf("cmd2[%d] = %s\n", j, cmd2[j]);
	// 	j++;
	// }

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
		child(fd, cmd1, env);
	else
		father(fd, cmd1, env, pid);
	close(fd[0]);
	close(fd[1]);
	return (0);
}
