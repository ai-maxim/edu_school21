/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdong <qdong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 12:09:35 by qdong             #+#    #+#             */
/*   Updated: 2021/01/08 22:37:55 by qdong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void  ft_printing(t_struct *data, va_list *ap)
{
	if (data->type == 's')
		print_str(va_arg(*ap, char *), data);
	if (data->type == 'c')
		print_char(va_arg(*ap, int), data);
	if (data->type == 'd' || data->type == 'i')
		print_deci(va_arg(*ap, int), data);
	if (data->type == 'u')
		print_unsig_deci(va_arg(*ap, unsigned int), data);
	if (data->type == 'p')
		print_poiter((int64_t)va_arg(*ap, void*), data);
	// print_p((unsigned long)va_arg(*ap, void*), data)
	// if (data->type == 'x' || data->type == 'X')
	// 	print_x(va_arg(*ap, unsigned int), data);
	// if (data->type == '%')
	// 	print_procent(va_arg(*ap, unsigned int), data);
}
