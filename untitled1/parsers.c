/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdong <qdong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 12:19:18 by qdong             #+#    #+#             */
/*   Updated: 2020/12/29 13:43:57 by qdong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		pars_str(char *format, t_struct *flags, va_list *ap)
{
	while (format[flags->i] != '\0')
	{
		if (format[flags->i] == '%')
		{
			flags->i++;
			if (ft_strchr("#-+ .*0123456789hljz", format[flags->i]))
				ft_pars_modifiers(format, flags, ap);
			if (ft_strchr("sSpdDioOuUxXcCbr%", format[flags->i]))
			{
				ft_printing(format, flags);
				if (flags->len == -1)
					return (0);
				ft_init_f(flags);
			}
		}
		else
			flags->len += write(flags->fd, &format[flags->i], 1);
		flags->i++;
	}
	return (flags->len);
}
