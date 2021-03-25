/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdong <qdong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 16:58:06 by qdong             #+#    #+#             */
/*   Updated: 2021/03/25 11:45:39 by qdong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		close_window(t_params *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	exit (0);
	return (0);
}

int				close_w(int	keycode, t_params	*vars)
{
//	printf("%d", keycode);
	if (keycode == 53)
		close_window(vars);
	return (0);
}

int				main(int argc, char **argv)
{
	t_scena 	*scena;
	t_params	params;

	if (!(argc >= 2 && argc <= 3))
		error_exit(1);
	else
	{
		scena = malloc(sizeof(t_scena));
		pars_data(argv[1], scena);
	}
	params.mlx = mlx_init();

	params.win = mlx_new_window(params.mlx, scena->widht, scena->height, "TEST");
	mlx_hook(params.win, 17, 0L, close_window, &params);
	mlx_hook(params.win, 2, 1L<<0, close_w, &params);
	ray_tracing(params.mlx, params.win, &scena);
	//free_scena(scena)  освобождает сцену и все что в ней есть
	mlx_loop(params.mlx);
}
