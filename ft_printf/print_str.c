/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdong <qdong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 12:18:25 by qdong             #+#    #+#             */
/*   Updated: 2020/12/28 14:43:29 by qdong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

void print_str(char *str, t_struct *f)
{
    int strlen;

    if (!str)
        str = NULL;
    strlen = ft_strlen(str);
    if (f->precision_specified && strlen > 0 && strlen > f->precision)
        strlen = f->precision;
    f->len += write(f->fd, str, strlen);
    while (f->width > strlen)
    {
        f->len += write(f->fd, " ", 1);
        f->width--;
    }
}

void ft_print_str_right(char *str, t_struct *f)
{
    int strlen;

    if (!str)
        str = NULL;
    strlen = ft_strlen(str);
    if (f->precision_specified && strlen > 0 && strlen > f->precision)
        strlen = f->precision;
    while (f->width > *str)
    {
        if (f->zero)
            f->len += write(f->fd, "0", 1);
        else
            f->len += write(f->fd, " ", 1);
        f->width--;
    }
    f->len += write(f->fd, str, strlen);
}

//static void ft_print_wide_str_left(wchar_t *wstr, t_struct *f)
//{
  //  int wstrsize;

//}
