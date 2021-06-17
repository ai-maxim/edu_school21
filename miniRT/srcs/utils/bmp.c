/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdong <qdong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 12:15:12 by qdong             #+#    #+#             */
/*   Updated: 2021/04/21 19:38:34 by qdong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	get_color_bmp(t_data *ap, int x, int y)
{
	char	*dst;

	dst = ap->addr + (y * ap->line_length + x * (ap->bits_per_pixel / 8));
	return (*(unsigned int *)dst);
}

int	check_type_screen(char *str)
{
	char	*type;
	int		i;

	type = "--save";
	i = 0;
	while (str[i] != '\0')
		i++;
	if (i < 6)
		return (0);
	i -= 6;
	while (str[i++] == *type++)
	{
		if (str[i] == '\0' && *type == '\0')
			return (1);
	}
	return (0);
}

static void	init_head(unsigned char *h_arr, int size, t_data *p, int temp)
{
	h_arr[0] = (unsigned char) 'B';
	h_arr[1] = (unsigned char) 'M';
	h_arr[2] = (unsigned char)(size % 256);
	h_arr[3] = (unsigned char)(size / 256 % 256);
	h_arr[4] = (unsigned char)(size / 256 / 256 % 256);
	h_arr[5] = (unsigned char)(size / 256 / 256 / 256);
	h_arr[10] = (unsigned char)54;
	h_arr[14] = (unsigned char)40;
	h_arr[18] = (unsigned char)(temp % 256);
	h_arr[19] = (unsigned char)(temp / 256 % 256);
	h_arr[20] = (unsigned char)(temp / 256 / 256 % 256);
	h_arr[21] = (unsigned char)(temp / 256 / 256 / 256);
	temp = p->win_y;
	h_arr[22] = (unsigned char)(temp % 256);
	h_arr[23] = (unsigned char)(temp / 256 % 256);
	h_arr[24] = (unsigned char)(temp / 256 / 256 % 256);
	h_arr[25] = (unsigned char)(temp / 256 / 256 / 256);
	h_arr[26] = (unsigned char)1;
	h_arr[28] = (unsigned char)24;
}

static void	get_screen(t_data *ap, int fd, int res)
{
	int		color;
	int		x;
	int		y;
	int		size_x;

	color = 0;
	x = 0;
	y = ap->win_y - 1;
	size_x = res;
	while (y >= 0)
	{
		while (x < size_x)
		{
			color = get_color_bmp(ap, x, y);
			write(fd, &color, 3);
			x++;
		}
		y--;
		x = 0;
	}
}

void	make_screen(t_data *ap)
{
	int				fd;
	unsigned char	header_arr[54];
	int				count;
	int				size;
	int				temp_res;

	temp_res = ap->win_x;
	if (ap->win_x % 4)
		temp_res = ap->win_x - (ap->win_x % 4);
	size = temp_res * ap->win_y + 54;
	count = 0;
	fd = open("./screen.bmp", O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU);
	while (count < 54)
	{
		header_arr[count] = (unsigned char)0;
		count++;
	}
	init_head(header_arr, size, ap, temp_res);
	write(fd, header_arr, 54);
	get_screen(ap, fd, temp_res);
	close(fd);
	exit(0);
}
