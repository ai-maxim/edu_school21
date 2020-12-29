/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdong <qdong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 12:07:54 by qdong             #+#    #+#             */
/*   Updated: 2020/12/29 15:26:44 by qdong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		print_char(unsigned char c, t_struct *f)
{
	f->len += write(f->fd, &c, 1);
	while (f->width > 1)
	{
		f->len += write(f->fd, " ", 1);
		f->width--;
	}
}

void		print_char_right(unsigned char c, t_struct *f)
{
	while (f->width > 1)
	{
		if (f->zero)
			f->len += write(f->fd, "0", 1);
		else
			f->len += write(f->fd, " ", 1);
		f->width--;
	}
	f->len += write(f->fd, &c, 1);
}
