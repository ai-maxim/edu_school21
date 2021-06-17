/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdong <qdong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 20:26:54 by qdong             #+#    #+#             */
/*   Updated: 2021/04/25 20:20:56 by qdong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	check_parse_c1(t_camera	*tmp, t_camera *new_cam, t_scena *scena)
{
	tmp = scena->cams;
	if (!tmp)
		scena->cams = new_cam;
	else
	{
		while (tmp)
		{
			if (tmp->next == NULL)
				break ;
			tmp = tmp->next;
		}
		new_cam->prev = tmp;
		tmp->next = new_cam;
	}
}

void	free_s(char **ar, char **n1, char **n2)
{
	free_array(ar);
	free_array(n1);
	free_array(n2);
}

void	check_parse_c0(char *line, t_camera	*new_cam)
{
	char	**array;
	char	**num;
	char	**num1;

	array = ft_split(line + 1, ' ');
	if (line[0] != ' ')
		ft_exit("Error! With whitespace Camera keys!\n");
	if (!(array[0] && array[1] && array[2]) || array[3])
		ft_exit("Error! With c keys!\n");
	num = ft_split(array[0], ',');
	if (!(num[0] && num[1] && num[2]) || num[3])
		ft_exit("Error! With origs!\n");
	new_cam->orig.x = ft_atof(num[0]);
	new_cam->orig.y = ft_atof(num[1]);
	new_cam->orig.z = ft_atof(num[2]);
	num1 = ft_split(array[1], ',');
	if (!(num1[0] && num1[1] && num1[2]) || num1[3])
		ft_exit("Error! With dirs!\n");
	new_cam->dir.x = ft_atof(num1[0]);
	new_cam->dir.y = ft_atof(num1[1]);
	new_cam->dir.z = ft_atof(num1[2]);
	new_cam->fov = ft_atof(array[2]);
	if (new_cam->fov > 360 || new_cam->fov < 0)
		ft_exit("Error! With fov!\n");
	free_s(array, num, num1);
}

void	parse_c(char *line, t_scena *scena)
{
	t_camera	*new_cam;
	t_camera	*tmp;

	tmp = NULL;
	scena->cam_flag = 1;
	new_cam = malloc(sizeof(t_camera));
	if (!new_cam)
		ft_exit("ERROR: malloc");
	new_cam->next = NULL;
	new_cam->prev = NULL;
	check_parse_c0(line, new_cam);
	check_parse_c1(tmp, new_cam, scena);
}
