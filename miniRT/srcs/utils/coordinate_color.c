/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordinate_color.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdong <qdong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 20:12:52 by qdong             #+#    #+#             */
/*   Updated: 2021/04/22 20:12:55 by qdong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec	get_coordinate(char **str)
{
	t_vec		tmp;

	tmp.x = ft_atof(str[0]);
	tmp.y = ft_atof(str[1]);
	tmp.z = ft_atof(str[2]);
	return (tmp);
}

t_color	get_color(char **str)
{
	t_color		tmp;

	if (!(str[0] && str[1] && str[2]) || str[3])
		ft_exit("Error! No argument is color!\n");
	tmp.r = ft_atoi(str[0]);
	tmp.g = ft_atoi(str[1]);
	tmp.b = ft_atoi(str[2]);
	if ((tmp.r < 0 || tmp.r > 255)
		|| (tmp.g < 0 || tmp.g > 255)
		|| (tmp.b < 0 || tmp.b > 255))
		ft_exit("Error! With colors!\n");
	return (tmp);
}
