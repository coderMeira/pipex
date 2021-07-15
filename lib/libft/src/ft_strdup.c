/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmeira <fmeira@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 16:31:35 by fmeira            #+#    #+#             */
/*   Updated: 2021/07/09 01:00:14 by fmeira           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	len;
	size_t	i;
	char	*p;

	len = ft_strlen(s1);
	i = 0;
	p = (char *)malloc(len * sizeof(char) + 1);
	if (p)
	{
		while (i < len)
		{
			p[i] = s1[i];
			i++;
		}
		p[i] = s1[i];
		return (p);
	}
	else
		return (NULL);
}
