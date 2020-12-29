/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdong <qdong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 12:13:59 by qdong             #+#    #+#             */
/*   Updated: 2020/12/29 13:41:20 by qdong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    char_print(t_struct *flags, int s)
{
	if (flags->minus)
		flags->fd += write(1, &s, 1);
	width_print(flags, flags->width, 1, 0);
	if (!(flags->minus))
		flags->fd += write(1, &s, 1);
}
