/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdong <qdong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 12:07:54 by qdong             #+#    #+#             */
/*   Updated: 2021/01/04 18:59:21 by qdong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		print_left(unsigned char c, t_struct *flags)
{
    flags->len += write(1, &c, 1);
    while (flags->width > 1)
    {
        // if (flags->zero)
        //     flags->len += write(1, "0", 1);
        // else
            flags->len += write(1, " ", 1);
        flags->width--;
    }
}

static void		print_right(unsigned char c, t_struct *flags)
{
    while (flags->width > 1)
    {
        if (flags->zero)
            flags->len += write(1, "0", 1);
        else
            flags->len += write(1, " ", 1);
        flags->width--;
    }
    flags->len += write(1, &c, 1);
}

void		    print_char(unsigned char c, t_struct *flags)
{
    if (flags->minus == 1)
        print_left(c, flags);
    else
        print_right(c, flags);
}
