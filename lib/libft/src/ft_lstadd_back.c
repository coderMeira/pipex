/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmeira <fmeira@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 19:09:05 by fmeira            #+#    #+#             */
/*   Updated: 2021/07/09 01:00:14 by fmeira           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

void	ft_lstadd_back(t_list **lst, t_list *n)
{
	if (lst)
	{
		if (*lst)
			ft_lstlast(*lst)->next = n;
		else
			*lst = n;
	}
}

void	ft_printlst(t_list *a)
{
	t_list	*current;
	int		*p;

	current = NULL;
	p = current -> content;
	current = a;
	while (current)
	{
		printf("%d\n", *p);
		current = current -> next;
	}
}
