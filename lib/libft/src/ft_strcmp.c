#include "../inc/libft.h"

t_bool	ft_strcmp(char *newstr, char *original)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(original);
	while (i < len)
	{
		if (original[i] != newstr[i])
			return (false);
		i++;
	}
	return (true);
}
