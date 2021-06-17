/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_normalaz.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdong <qdong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 16:37:28 by qdong             #+#    #+#             */
/*   Updated: 2021/04/21 19:56:49 by qdong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	check_normalaz(char *str1, char *str2, char *str3)
{
	if (ft_atof(str1) > 1 || ft_atof(str1) < -1)
		ft_exit("ERROR - normalaz");
	if (ft_atof(str2) > 1 || ft_atof(str2) < -1)
		ft_exit("ERROR - normalaz");
	if (ft_atof(str3) > 1 || ft_atof(str3) < -1)
		ft_exit("ERROR - normalaz");
}

void	free_array(char **r)
{
	size_t	i;

	i = 0;
	while (r[i])
		free(r[i++]);
	free(r);
}
