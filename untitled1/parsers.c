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

int		parsers(char *format, t_struct *flags, va_list *ap)
{
    while (format[flags->i] != '\0')
	{
        if (format[flags->i] == '%')
		{
            flags->i++;
            ft_pars_modifiers(format, flags, ap);
            ft_printing(format, flags, ap);
            if (flags->len == -1)
                return (0);
            ft_reset_flags(flags);
		}
		else
        {
            flags->len += write(1, &format[flags->i], 1);
            flags->i++;
        }
	}
	return (flags->len);
}

char    *ft_chec_type(char *format, t_struct *flags)
{
    if (format[flags->i] == 'c' || format[flags->i] == 's' || format[flags->i] == 'p' ||
        format[flags->i] == 'd' || format[flags->i] == 'i' || format[flags->i] == 'u' ||
        format[flags->i] == 'x' || format[flags->i] == 'X' || format[flags->i] == '%')
    {
        flags->type = format[flags->i];
        flags->i++;
    }
    else
    {
        flags->type = -1;
        return (NULL);
    }
    return (format);
}
