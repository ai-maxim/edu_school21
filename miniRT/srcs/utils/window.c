/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdong <qdong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 16:37:09 by qdong             #+#    #+#             */
/*   Updated: 2021/04/10 17:19:40 by qdong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// int		screen_resolution(t_params *vars)
// {

// }

int	close_window(t_params *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	exit (0);
	return (0);
}

int	close_w(int	keycode, t_params	*vars)
{
//	printf("%d", keycode);
	if (keycode == 53)
		close_window(vars);
	return (0);
}
