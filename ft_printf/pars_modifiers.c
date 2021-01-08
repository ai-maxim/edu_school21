/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_modifiers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdong <qdong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 15:28:47 by qdong             #+#    #+#             */
/*   Updated: 2021/01/08 19:46:00 by qdong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//void    length(char *format, t_struct *flags)
// для бонуса

void		flag(char *format, t_struct *flags)
{
	while (ft_strchr("-0.*", format[flags->i]))
	{
		if (format[flags->i] == '-')
			flags->minus = 1;
		else if ((format[flags->i]) == '0')
			flags->zero = 1;
		else if (format[flags->i] == '.')
			flags->dot = 1;
		else
			return;
		flags->i++;
	}
}

int			width(char *format, t_struct *flags, va_list *ap)
{
	int		width;

	if (ft_isdigit(format[flags->i]) && format[flags->i] != '0')
	{
		flags->width = ft_atoi(&format[flags->i]);
 		while (ft_isdigit(format[flags->i]))
				flags->i++;
	}
	else if (format[flags->i] == '*')
	{
		width = va_arg(*ap, int);
		if (width >= 0)
			flags->width = width;
		else
		{
			flags->minus = 1;
			flags->zero = 0;
			flags->width = -width;
		}
		while (format[flags->i] == '*')
			(flags->i)++;
	}
	return (1);
}

int			accuracy(char *format, t_struct *flags, va_list *ap)
{
	int		accuracy;

	if (format[flags->i] == '.' || flags->dot == 1)
	{
		if (format[flags->i] == '.')
		{
			flags->dot = 1;
			flags->i++;
		}
		flags->accuracy_specified = 1;
		if(ft_isdigit(format[flags->i]))
		{
			flags->accuracy = ft_atoi(&format[flags->i]);
			while (ft_isdigit(format[flags->i]))
				flags->i++;
		}
		else if (format[flags->i] == '*')
		{
			accuracy = va_arg(*ap, int);
			if (accuracy >= 0)
				flags->accuracy = accuracy;
			else
				flags->accuracy_specified = 0;
			while (format[flags->i] == '*')
				(flags->i)++;
		}
	}
	return (1);
}

int         pars_modifiers(char *format, t_struct *flags, va_list *ap)
{
	flag(format, flags);
	if (flags->dot == 0 && !width(format, flags, ap))
		return (0);
	if (!accuracy(format, flags, ap))
		return (0);
	chec_type(format, flags);
	return (1);
}
