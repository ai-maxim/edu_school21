/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdong <qdong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 16:58:06 by qdong             #+#    #+#             */
/*   Updated: 2021/04/21 12:28:05 by qdong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	init_zero(t_close *cl)
{
	cl->t = INFINITY;
	cl->obj_col.r = 0;
	cl->obj_col.g = 0;
	cl->obj_col.b = 0;
}

void	check_screen_size(t_scena *scena, void *mlx)
{
	int	w;
	int	h;

	mlx_get_screen_size(mlx, &w, &h);
	if (scena->widht > w)
		scena->widht = w;
	if (scena->height > h)
		scena->height = h;
	if (scena->ambient != 1)
		ft_exit("Error! Where A key?\n");
	if (scena->cam_flag != 1)
		ft_exit("Error! Where cam?\n");
}

void	put_img_to_win(t_params *params, t_data *imgs, t_scena *scena)
{
	params->scena = scena;
	mlx_hook(params->win, 17, 0L, close_window, params);
	mlx_hook(params->win, 2, 1L << 0, close_w, params);
	mlx_put_image_to_window(params->mlx, params->win, imgs->img, 0, 0);
	mlx_loop(params->mlx);
}

int	main(int argc, char **argv)
{
	t_data		imgs;
	t_scena		scena;
	t_params	params;

	if (argc != 2 && argc != 3)
		error_exit(-1);
	error_invalid_file(argc, argv);
	ft_bzero(&scena, sizeof(t_scena));
	ft_bzero(&imgs, sizeof(t_data));
	ft_bzero(&params, sizeof(t_params));
	pars_data(argv[1], &scena);
	check_screen_size(&scena, &params.mlx);
	params.mlx = mlx_init();
	params.win = mlx_new_window(params.mlx, scena.widht, scena.height, "miniRT");
	ray_tracing(params.mlx, params.win, &scena, &imgs);
	params.img = &imgs;
	if (argc == 3 && check_type_screen(argv[2]))
		make_screen(&imgs);
	else if (argc == 3)
		ft_exit("Error! invalid imput!\n");
	if (argc == 2)
		put_img_to_win(&params, &imgs, &scena);
	return (0);
}
