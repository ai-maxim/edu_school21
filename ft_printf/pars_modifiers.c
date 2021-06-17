/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_modifiers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdong <qdong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 15:28:47 by qdong             #+#    #+#             */
/*   Updated: 2021/01/10 20:26:38 by qdong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			flag(char *format, t_struct *flags)
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
			return ;
		flags->i++;
	}
}

int				width(char *format, t_struct *flags, va_list *ap)
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

static void		acc_star(char *format, t_struct *flags, va_list *ap)
{
	flags->accuracy = va_arg(*ap, int);
	if (flags->accuracy < 0)
	{
		flags->accuracy = 0;
		flags->dot = 0;
		flags->accuracy_specified = 0;
	}
	while (format[flags->i] == '*')
		(flags->i)++;
}

int				accuracy(char *format, t_struct *flags, va_list *ap)
{
	if (format[flags->i] == '.' || flags->dot == 1)
	{
		if (format[flags->i] == '.')
		{
			flags->dot = 1;
			flags->i++;
		}
		flags->accuracy_specified = 1;
		if (ft_isdigit(format[flags->i]))
		{
			flags->accuracy = ft_atoi(&format[flags->i]);
			while (ft_isdigit(format[flags->i]))
				flags->i++;
		}
		else if (format[flags->i] == '*')
			acc_star(format, flags, ap);
	}
	return (1);
}

int				pars_modifiers(char *format, t_struct *flags, va_list *ap)
{
	flag(format, flags);
	if (flags->dot == 0 && !width(format, flags, ap))
		return (0);
	if (!accuracy(format, flags, ap))
		return (0);
	chec_type(format, flags);
	return (1);
}
