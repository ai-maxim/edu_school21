/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdong <qdong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 12:09:17 by qdong             #+#    #+#             */
/*   Updated: 2021/01/10 20:04:59 by qdong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int					ft_printf(const char *format, ...)
{
	va_list			ap;
	int				out;
	t_struct		flags;

	flags = (t_struct){0, 0, 0, 0, 0, 0, 0, 0, 0};
	va_start(ap, format);
	if ((out = parsers((char *)format, &flags, &ap)) == -1)
		return (-1);
	va_end(ap);
	return (out);
}
