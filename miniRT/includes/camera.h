/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdong <qdong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 16:55:57 by qdong             #+#    #+#             */
/*   Updated: 2021/04/20 15:01:56 by qdong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H

typedef struct		s_camera
{
	t_vec			orig;
	t_vec			dir; // направление по умолчанию по оси z
	double			fov; //ugol obzora
	struct s_camera	*next;
	struct s_camera	*prev;
}					t_camera;

#endif
