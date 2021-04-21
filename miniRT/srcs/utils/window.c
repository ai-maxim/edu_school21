/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdong <qdong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 16:37:09 by qdong             #+#    #+#             */
/*   Updated: 2021/04/20 20:28:12 by qdong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "unistd.h"

int	close_window(t_params *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	exit (0);
	return (0);
}

void	camera_go(t_params *vars)
{
	mlx_destroy_image(vars->mlx, vars->img->img);
	ray_tracing(vars->mlx, vars->win, vars->scena, vars->img);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img->img, 0, 0);
}

int	close_w(int	keycode, t_params *vars)
{
	if (keycode == 53)
		close_window(vars);
	else if (keycode == 123)
	{
		if (!(vars->scena->cams->prev))
			return (0);
		vars->scena->cams = vars->scena->cams->prev;
		camera_go(vars);
	}
	else if (keycode == 124)
	{
		if (!(vars->scena->cams->next))
			return (0);
		vars->scena->cams = vars->scena->cams->next;
		camera_go(vars);
	}
	return (0);
}
