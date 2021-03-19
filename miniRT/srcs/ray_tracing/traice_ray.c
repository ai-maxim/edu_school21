/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   traice_ray.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdong <qdong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 16:57:39 by qdong             #+#    #+#             */
/*   Updated: 2021/03/19 20:21:51 by qdong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void 	ray_tracing(void *mlx , void *window, t_scena *scena)
{
	// int			mlx_x;
	// int			mlx_y; // итераторы для функции mlx_pixel_put
	//  нужно создать буфер и из него выводить на окно
	// float		x_angle;
	// float		y_angle;
	int			color;
	float		x_ray;
	float		y_ray;
	float		i;
	float		j;
	float		asspect;
	t_vec		ray;
//	t_vplane	*okno_prosmotra;

	asspect = (float)scena->widht / (float)scena->height;
	printf("\nflag - %d %d %f\n", scena->height, scena->widht, asspect);
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
//			printf("\nray - %f %f\n", x_ray, y_ray);
			ray  = new_vector(x_ray, y_ray, 1);
			normalize_vec(ray);
//			printf("%d\n", sfera_intersect(scena->cams, ray, scena->objects));
			// intesect();
			// if (scena->objects->type == 'p' &&
			// 	(plane_intersect(scena->cams, ray, scena->objects)))
			// 	color = 65280;
			if (scena->objects->type == 'q' &&
				(sq_intersect(scena->cams, ray, scena->objects)))
				color = 65280;
			else
				color = 0;
			mlx_pixel_put(mlx, window, j, i, color);
//			j++;
		}
//		i++;
	}
}

//	printf("FOV: %f\n", scena->cams->fov);
	// okno_prosmotra = get_vian_plane(scena->widht, scena->height, scena->cams->fov);
	// mlx_y = 0;
	// y_angle = (scena->height / 2);
	// printf("scena->height: %d\n", scena->height);
	// printf("      y_angle: %f\n", y_angle);
	// while (y_angle >= (scena->height / 2) * (-1))
	// {
	// 	mlx_x = 0;
	// 	y_ray = y_angle * okno_prosmotra->y_pixel;
	// 	x_angle = (scena->widht / 2) * (-1);
	// 	while(x_angle <= scena->widht / 2)
	// 	{
	// 		x_ray = x_angle * okno_prosmotra->x_pixel;
	// 		ray = new_vector(x_ray, y_ray, -1);
	// 		normalize_vec(ray);
	// 		printf("Type: %d\n", scena->objects->type);
	// 		if (scena->objects->type == 'p' && (plane_intersect(scena->cams, ray, scena->objects)))
	// 			color = 65280;
	// 		else
	// 			color = 0;
	// 		mlx_pixel_put(mlx, window, mlx_x, mlx_y, color);
	// 		printf("mlx_x = %d mlx_y %d\n", mlx_x, mlx_y);
	// 		x_angle++;
	// 		mlx_x++;
	// 	}
	// 	y_angle--;
	// 	mlx_y++;
	// }



// t_vplane	*get_vian_plane(float widht, float height, float fov)
// {
// 	t_vplane	*vplane;
// 	int			aspect_ratia;	// соотношение ширины и высоты

// 	fov = 1; // 2 * atan(y1 / f)
// 	vplane = malloc(sizeof(t_vplane));
// 	if (!vplane)
// 		error_exit(-1);
// 	aspect_ratia = widht / height;
// 	vplane->widht = 1;
// 	vplane->height = vplane->widht / aspect_ratia;
// 	vplane->x_pixel = vplane->widht / widht;
// 	vplane->y_pixel = vplane->height / height;
// 	return (vplane);
// }
