/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdong <qdong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 12:09:35 by qdong             #+#    #+#             */
/*   Updated: 2020/12/29 15:27:47 by qdong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void  ft_printing(char *str, t_struct *data, va_list *ap)
{
	if (data->type == 's')
		print_str(va_arg(*ap, char *), data);
	if (data->type == 'c')
	    print_char(va_arg(*ap, char *), data);

	// if (data->i == 'd' || data->i == 'i')
	//   print_deci(data);
	// if (data->i == 'u')
	//     print_unsig_deci(data);
	// if (data->i == 'p')
	//     print_poiter(data);
	// if (data->i == 'x')
	//     print_x(data);
	// if (data->i == 'X')
	//     print_xx(data);
	// if (data->i == '%')
	//     print_procent(data);
}
