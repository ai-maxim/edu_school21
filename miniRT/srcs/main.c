/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdong <qdong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 16:58:06 by qdong             #+#    #+#             */
/*   Updated: 2021/03/19 20:33:31 by qdong            ###   ########.fr       */
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
	t_params	params;
	// char 		*out = argv[1];
	// t_general	data;
	// t_scena 	scena;

	// if (argc > 1)
	// 	error_exit(1);
	// pars_data(&data, scena);

	params.mlx = mlx_init();

	// t_vec		plane_center = new_vector(1, 2, 3);
	// t_general	*plane = new_plane(plane_center, new_vector(0, 1, 0));

	// t_vec		cylinder_center = new_vector(0.0, 0.0, 30.6);
	// t_vec		cy_direction = new_vector(0.0, 1.0, 0.0);
	// t_general	*cylinder = new_cylinder(cylinder_center, cy_direction, 7.1, 21.42);

	// t_vec		sfera_center = new_vector(1, 19, -34);
	// t_general 	*sfera = new_sfera(sfera_center, 12/2);

	// t_vec		tr_center = new_vector(0, 0, 1);
	// t_vec		c = new_vector(10, 20, 10);
	// t_vec		c = new_vector(scena , 20, 10);
	// t_vec		c1 = new_vector(10, 10, 20);
	// t_vec		c2 = new_vector(20, 10, 10);
	// t_general	*triangle = new_triangle(0.0, 1.0, 0.0);

	t_vec		sq_center = new_vector(0, 10, 4);
	t_general	*square = new_square(sq_center, new_vector(0, 0, 1.0), 3);

	t_vec		cam_origen = new_vector(0, 0, 0);
	t_vec		cam_derection= new_vector(0, 0, 0);
	t_camera	*cam = new_camera(cam_origen, cam_derection, 70);
	// t_scena		*scena = new_scena(cam, scena->objects);
	t_scena		*scena = new_scena(cam, square);
	scena->widht = 500;
	scena->height = 700;
//				printf("\nflag - %d %d\n", scena->height, scena->widht);
	params.win = mlx_new_window(params.mlx, scena->widht, scena->height, "TEST");
	mlx_hook(params.win, 17, 0L, close_window, &params);
	mlx_hook(params.win, 2, 1L<<0, close_w, &params);
	ray_tracing(params.mlx, params.win, scena);
	//free_scena(scena)  освобождает сцену и все что в ней есть
	mlx_loop(params.mlx);
	return (0);
}
