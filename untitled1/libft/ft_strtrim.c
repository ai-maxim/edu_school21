/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdong <qdong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 23:05:44 by qdong             #+#    #+#             */
/*   Updated: 2020/11/16 15:42:22 by qdong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *str, char const *set)
{
	const char *begin;
	const char *end;

	if (!str || !set)
		return (NULL);
	while (*str && ft_strchr(set, *str))
		str++;
	begin = str;
	end = str;
	while (*str)
	{
		if (!ft_strchr(set, *str))
			end = str;
		str++;
	}
	return (ft_substr(begin, 0, end - begin + 1));
}
