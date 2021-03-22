/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   traice_ray.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdong <qdong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 16:57:39 by qdong             #+#    #+#             */
/*   Updated: 2021/03/22 11:31:05 by qdong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void 	ray_tracing(void *mlx , void *window, t_scena *scena)
{
	//  нужно создать буфер и из него выводить на окно
	int			color;
	float		x_ray;
	float		y_ray;
	float		i;
	float		j;
	float		asspect;
	t_ray		ray;
//	t_vplane	*okno_prosmotra;

	asspect = (float)scena->widht / (float)scena->height;
	// printf("\nflag - %d %d %f\n", scena->height, scena->widht, asspect);
	ray.origin = scena->cams->origin;
	printf("\n 444 %f", scena->cams->origin.z);
	i = 0;
	while (i++ < scena->height)
	{
		j = 0;
		while (j++ < scena->widht)
		{
			x_ray = ((j / scena->widht) - 0.5);
			y_ray = (0.5 - (i / scena->height));
			x_ray *= asspect > 1 ? asspect : 1;
			y_ray /= asspect < 1 ? asspect : 1;
			// printf("\nray - %f %f\n", x_ray, y_ray);
			ray.direction = new_vector(x_ray, y_ray, 1);
			ray.direction = normalize_vec(ray.direction);
			// printf("TEST: %f\n", ray.direction.y);
			if (intersect(ray, scena->objects) < 1000000)
				color = 65280;
			else
				color = 0;
			mlx_pixel_put(mlx, window, j, i, color);
		}
	}
	printf("\n finish");
}
