/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdong <qdong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 22:19:33 by qdong             #+#    #+#             */
/*   Updated: 2020/11/14 19:23:14 by qdong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char		*head;
	char		*tmp;
	size_t		i;

	if (!*needle)
		return ((char *)haystack);
	tmp = (char *)needle;
	while (*haystack && len)
	{
		head = (char *)haystack;
		i = 0;
		while ((*haystack == *needle) && *needle && i < len)
		{
			++haystack;
			++needle;
			++i;
		}
		if (!*needle)
			return ((char *)head);
		needle = tmp;
		haystack = head + 1;
		--len;
	}
	return (0);
}
