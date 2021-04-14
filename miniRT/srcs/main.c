/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdong <qdong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 16:58:06 by qdong             #+#    #+#             */
/*   Updated: 2021/04/11 19:01:50 by qdong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	main(int argc, char **argv)
{
	t_data		imgs;
	t_scena 	*scena;
	t_params	params;

	// if(argc == 3)
	// 	make_screen(imgs);
	if (argc != 2 && argc != 3)
		error_exit(-1);
	error_invalid_file(argc, argv);
	scena = (t_scena *)malloc(sizeof(t_scena));
	scena->light = NULL;
	scena->cams = NULL;
	scena->objs = NULL;
	puts("test0");
	pars_data(argv[1], scena);
	puts("test1");
	params.mlx = mlx_init();
	params.win = mlx_new_window(params.mlx, scena->widht, scena->height, "TEST");
	ray_tracing(params.mlx, params.win, scena, &imgs);
	mlx_hook(params.win, 17, 0L, close_window, &params);
	mlx_hook(params.win, 2, 1L<<0, close_w, &params);
	mlx_put_image_to_window(params.mlx, params.win, imgs.img, 0, 0);
	//free_scena(scena)  освобождает сцену и все что в ней есть
	mlx_loop(params.mlx);
	return (0);
}
