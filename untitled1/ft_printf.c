/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdong <qdong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 12:09:17 by qdong             #+#    #+#             */
/*   Updated: 2020/12/29 13:06:37 by qdong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int					ft_printf(const char *format, ...)
{
	va_list			ap;
//	char			*str;
	int				out;
	t_struct		flags;

	flags = (t_struct){0, 0, 0, 0, 0, 0, 0, 0, 0};

	va_start(ap, format);
	if ((out = parsers((char *)format, &flags, &ap)) == -1)
		return (-1);
//	str = va_arg(ap, char*);
	va_end(ap);
	return(out);
}
