#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/wait.h>
# include <errno.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <string.h>
# include "../lib/libft/inc/libft.h"

# define	FD_WRITE_END	1
# define	FD_READ_END		0

void	get_path(char *cmd, char *envp[], char **f_path);
void	free_matrix(char **matrix);
char	**split_cmd_arg(char *argv);
void	check_argv(int argc);
void	check_fd(int fd, char *file);

#endif
