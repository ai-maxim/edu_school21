/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   traice_ray.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdong <qdong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 16:57:39 by qdong             #+#    #+#             */
/*   Updated: 2021/03/24 16:54:40 by qdong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void 	ray_tracing(void *mlx , void *window, t_scena *scena)
{
	//  нужно создать буфер и из него выводить на окно
	int			color;
	double		x_ray;
	double		y_ray;
	double		i;
	double		j;
	double		aspect;
	t_ray		ray;
	t_objs	*obj;
//	t_vplane	*okno_prosmotra;

	aspect = (double)scena->widht / (double)scena->height;
	ray.origin = scena->cams->origin;
	// printf("\n 444 %f", scena->cams->origin.z);
	i = 0;
	while (i++ < scena->height)
	{
		j = 0;
		while (j++ < scena->widht)
		{
			x_ray = ((j / scena->widht) - 0.5);
			y_ray = (0.5 - (i / scena->height));
			x_ray *= aspect > 1 ? aspect : 1;
			y_ray /= aspect < 1 ? aspect : 1;
			ray.direction = new_vector(x_ray, y_ray, 1);
			if ((obj = intersect(ray, scena->objs, 1, 1000000)))
				color = obj->color;
			else
				color = 0;
			mlx_pixel_put(mlx, window, j, i, color);
		}
	}
	printf("\n finish");
}

// typedef struct s_new
// {
// 	void		*mlx;
// 	void		*window;
// 	t_scena		*scena;
// }				t_new;


// void 	ray_tracing_new(t_new *params)
// {
// 	void	*mlx = params->mlx;
// 	void	*window = params->window;
// 	t_scena *scena = params->scena;

// 	//  нужно создать буфер и из него выводить на окно
// 	int			color;
// 	double		x_ray;
// 	double		y_ray;
// 	double		i;
// 	double		j;
// 	double		aspect;
// 	t_ray		ray;
// 	t_objects	*obj;
// //	t_vplane	*okno_prosmotra;

// 	aspect = (double)scena->widht / (double)scena->height;
// 	ray.origin = scena->cams->origin;
// 	// printf("\n 444 %f", scena->cams->origin.z);
// 	i = 0;
// 	while (i++ < scena->height)
// 	{
// 		j = 0;
// 		while (j++ < scena->widht)
// 		{
// 			x_ray = ((j / scena->widht) - 0.5);
// 			y_ray = (0.5 - (i / scena->height));
// 			x_ray *= aspect > 1 ? aspect : 1;
// 			y_ray /= aspect < 1 ? aspect : 1;
// 			ray.direction = new_vector(x_ray, y_ray, 1);
// 			if ((obj = intersect(ray, scena->objects, 1, 1000000)))
// 				color = obj->color;
// 			else
// 				color = 0;
// 			mlx_pixel_put(mlx, window, j, i, color);
// 		}
// 	}
// 	printf("\n finish");
// }
