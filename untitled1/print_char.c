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

void		print_char(unsigned char c, t_struct *flags)
{
	flags->len += write(flags->fd, &c, 1);
	while (flags->width > 1)
	{
		flags->len += write(flags->fd, " ", 1);
		flags->width--;
	}
}

void		print_char_right(unsigned char c, t_struct *flags)
{
	while (flags->width > 1)
	{
		if (flags->zero)
			flags->len += write(flags->fd, "0", 1);
		else
			flags->len += write(flags->fd, " ", 1);
		flags->width--;
	}
	flags->len += write(flags->fd, &c, 1);
}
