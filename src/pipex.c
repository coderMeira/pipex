#include "../inc/pipex.h"

char	*ft_joinspace(char *s1, char *s2)
{
	char	*new_str;
	int		i;
	int		j;

	i = 0;
	new_str = malloc(sizeof(char) * ft_strlen(s1) + ft_strlen(s2) + 2);
	while (s1[i])
	{
		new_str[i] = s1[i];
		i++;
	}
	j = 0;
	new_str[i++] = ' ';
	while (s2[j])
		new_str[i++] = s2[j++];
	new_str[i] = '\0';
	return (new_str);
}

static	char	**path_finder(char **env)
{
	int		i;
	char	**paths;

	i = 0;
	paths = NULL;
	while (env)
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
		{
			paths = ft_split(env[i] + 5, ':');
			break ;
		}
		i++;
	}
	return (paths);
}

static	void	call_parent(char **argv, int *fd, char **env)
{
	char	**args;
	char	**paths;
	int		out;
	int		i;

	out = open(argv[4], O_WRONLY | O_CREAT, 0777);
	if (out == -1)
		exit(-1);
	paths = path_finder(env);
	args = ft_split(argv[3], ' ');
	dup2(out, STDOUT_FILENO);
	close(out);
	dup2(fd[0], STDIN_FILENO);
	close(fd[0]);
	close(fd[1]);
	i = 0;
	while (paths[i])
	{
		paths[i] = ft_strjoin(paths[i], "/");
		paths[i] = ft_strjoin(paths[i], args[0]);
		execve(paths[i], args, NULL);
		i++;
	}
	free_paths(paths);
	free_paths(args);
}

static	void	call_child(char **argv, int *fd, char **env)
{
	int		i;
	char	**paths;
	char	*new_str;
	char	**args;

	new_str = ft_joinspace(argv[2], argv[1]);
	paths = path_finder(env);
	args = ft_split(new_str, ' ');
	dup2(fd[1], STDOUT_FILENO);
	close(fd[0]);
	close(fd[1]);
	i = 0;
	while (paths[i])
	{
		paths[i] = ft_strjoin(paths[i], "/");
		paths[i] = ft_strjoin(paths[i], args[0]);
		execve(paths[i], ft_split(new_str, ' '), NULL);
		i++;
	}
	free_paths(paths);
	free_paths(args);
	free(new_str);
}

int	main(int argc, char **argv, char **env)
{
	pid_t	pid;
	int		fd[2];
	int		i;

	if (argc != 5)
	{
		ft_putstr_fd("Usage : ./pipex infile cmd1 cmd2 outfile\n", 2);
		return(0);
	}
	if (pipe(fd) == -1)
		exit(-1);
	i = open(argv[1], O_RDONLY);
	if (i == -1)
		exit(1);
	pid = fork();
	if (pid == -1)
		exit(1);
	if (pid == 0)
		call_child(argv, fd, env);
	else
		call_parent(argv, fd, env);
	close(fd[0]);
	close(fd[1]);
	waitpid(pid, NULL, 0);
}
