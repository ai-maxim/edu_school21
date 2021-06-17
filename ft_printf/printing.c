/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdong <qdong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 12:09:35 by qdong             #+#    #+#             */
/*   Updated: 2021/01/10 19:34:26 by qdong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	printing(t_struct *data, va_list *ap)
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
		print_pointer(va_arg(*ap, unsigned long long int), data);
	if (data->type == 'x' || data->type == 'X')
		print_x(va_arg(*ap, unsigned int), data);
	if (data->type == '%')
		print_procent(data);
}
