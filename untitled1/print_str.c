/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdong <qdong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 12:18:25 by qdong             #+#    #+#             */
/*   Updated: 2020/12/29 13:46:30 by qdong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

void	print_str(char *str, t_struct *flags)
{
    int strlen;

    if (!str)
        str = NULL;
    strlen = ft_strlen(str);
    if (flags->accuracy_specified && strlen > 0 && strlen > flags->accuracy)
        strlen = flags->accuracy;
    flags->len += write(flags->fd, str, strlen);
    while (flags->width > strlen)
    {
        flags->len += write(flags ->fd, " ", 1);
        flags->width--;
    }
}

void	ft_print_str_right(char *str, t_struct *flags)
{
	int strlen;

	if (!str)
		str = NULL;
	strlen = ft_strlen(str);
	if (flags->accuracy_specified && strlen > 0 && strlen > flags->accuracy)
		strlen = flags->accuracy;
	while (flags->width > *str)
	{
		if (flags->zero)
			flags->len += write(flags->fd, "0", 1);
		else
			flags->len += write(flags->fd, " ", 1);
		flags->width--;
	}
	flags->len += write(flags->fd, str, strlen);
}

//static void ft_print_wide_str_left(wchar_t *wstr, t_struct *f)
//{
  //  int wstrsize;

//}
