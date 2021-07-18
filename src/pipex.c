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

static void trim(char *str, char *cmd)
{
	int		i;
	int		j;
	char	*newstr;

	i = 0;
	j = 0;
	newstr = ft_calloc((ft_strlen(str) - 3), sizeof(char));
	while (!(ft_isalpha(str[i])))
		i++;
	while (ft_isalpha(newstr[i]))
		newstr[j++] = str[i++];
	cmd = newstr;
}

int	main(int ac, char **av)
{
	int		fd[2];
	pid_t	pid;
	char	*cmd1;
	char	*cmd2;
	int 	i = 0;

	//trim(av[1], cmd1);
	//trim(av[2], cmd2);

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

	//printf("cmd 1 = %s\n", cmd1);
	//printf("cmd 2 = %s\n", cmd2);

	while (ac--)
	{
		printf("av %d = %s\n", i, av[i]);
		i++;
	}
	free(cmd1);
	free(cmd2);
	return (0);
}
