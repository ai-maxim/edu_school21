/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdong <qdong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 12:18:25 by qdong             #+#    #+#             */
/*   Updated: 2021/01/04 18:42:52 by qdong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

static void	print_right(char *str, t_struct *flags)
{
	int len;

	len = ft_strlen(str);
	if (flags->accuracy_specified && len > 0 && len > flags->accuracy)
		len = flags->accuracy;
	while (flags->width > len)
	{
		if (flags->zero)
			flags->len += write(1, "0", 1);
		else
			flags->len += write(1, " ", 1);
		flags->width--;
	}
	flags->len += write(1, str, len);
}

static void print_left(char *str, t_struct *flags)
{
    int len;

    len = ft_strlen(str);
    if (flags->accuracy_specified && len > 0 && len > flags->accuracy) {
        len = flags->accuracy;
    }
    flags->len += write(1, str, len);
    while (flags->width > len)
    {
        // if (flags->zero)
        //     flags->len += write(1, "0", 1);
        // else
            flags->len += write(1, " ", 1);
        flags->width--;
    }
}

void	print_str(char *str, t_struct *flags)
{
    if (!str)
        str = "(null)";
    if (flags->minus == 1)
        print_left(str, flags);
    else
        print_right(str, flags);
}
