/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmeira <fmeira@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 20:08:19 by fmeira            #+#    #+#             */
/*   Updated: 2021/07/09 01:00:14 by fmeira           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*p;
	unsigned char	*k;
	int				i;

	p = (unsigned char *)s1;
	k = (unsigned char *)s2;
	i = 0;
	if (n == 0)
		return (0);
	while (n-- && p && k)
	{
		if (p[i] != k[i])
			return (p[i] - k[i]);
		i++;
		if (!p[i])
			return (0);
	}
	return (0);
}
