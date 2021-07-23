#include "../inc/libft.h"

void	ft_free_s_vector(char **str, int size)
{
	int	i;

	i = 0;
	while (i < size)
		free(str[i++]);
}
