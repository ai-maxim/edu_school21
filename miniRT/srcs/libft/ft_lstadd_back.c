/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdong <qdong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 21:22:42 by qdong             #+#    #+#             */
/*   Updated: 2021/03/08 16:22:44 by qdong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (!new)
		return (0);
	if (!*lst)
	{
		*lst = new;
		new->next = NULL;
	}
	if (lst && *lst)
	{
		last = ft_lstlast(*lst);
		last->next = new;
		new->next = NULL;
	}
	return (1);
}
