/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdong <qdong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 16:55:57 by qdong             #+#    #+#             */
/*   Updated: 2021/04/21 17:21:57 by qdong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H

typedef struct s_camera
{
	t_vec			orig;
	t_vec			dir;
	double			fov;
	struct s_camera	*next;
	struct s_camera	*prev;
}					t_camera;

#endif
