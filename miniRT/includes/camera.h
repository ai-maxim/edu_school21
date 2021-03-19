/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdong <qdong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 16:55:57 by qdong             #+#    #+#             */
/*   Updated: 2021/03/17 13:56:43 by qdong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H

typedef struct s_camera
{
	t_vec		origin;
	t_vec		derection; // направление по умолчанию по оси z
	float		fov; //ugol obzora
}				t_camera;

 t_camera *new_camera(t_vec origin, t_vec derection, float fov);

#endif
