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

static char** parse(char **av, int *i, int *j)
{
	char	**newcmd;

	newcmd = malloc(sizeof(char *) * 2);
	newcmd[0] = ft_strdup(av[*i]);
	while (av[++*i][0] == '-')
		newcmd[++*j] = av[*i];
	return (newcmd);
}

int	main(int ac, char **av)
{
	int		fd[2];
	pid_t	pid;
	char	**cmd1;
	char	**cmd2;
	int 	j;
	int 	i;

	j = 0;
	i = 2;
	cmd1 = parse(av, &i, &j);
	printf("%d\n", i);
	printf("%d\n", j);
	j = 0;
	cmd2 = parse(av, &i, &j);

	printf("cmd 1[0] = %s\n", cmd1[0]);
	printf("cmd 1[1] = %s\n", cmd1[1]);
	printf("cmd 2[0] = %s\n", cmd2[0]);
	printf("cmd 2[1] = %s\n", cmd2[1]);
	// if (ac != 5)
	// {
	// 	ft_putstr_fd("Usage : ./pipex infile cmd1 cmd2 outfile\n", 2);
	// 	return(0);
	// }
	// if ((pipe(fd) == -1))
	// {
	// 	perror("pipe error");
	// 	exit(-1);
	// }
	// pid = fork();
	// if (pid == -1)
	// {
	// 	perror("fork error");
	// 	exit(1);
	// }
	// else if (pid == 0)
	// 	child(av, fd, pid);
	// else
	// 	father(av, fd, pid);
	// wait(NULL);
	//printf("cmd 1.1 = %s\n", cmd1[1]);
	//printf("cmd 2 = %s\n", cmd2);

	// while (ac--)
	// {
	// 	printf("av %d = %s\n", i, av[i]);
	// 	i++;
	// }
	free(cmd1);
	free(cmd2);
	return (0);
}
