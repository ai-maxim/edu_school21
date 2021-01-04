/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_deci.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdong <qdong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 12:19:34 by qdong             #+#    #+#             */
/*   Updated: 2021/01/04 21:12:07 by qdong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void print_left(char *str, t_struct *flags)
{
	if (str < 0 && str[0] == '-')
	{
		write(1, '-', 1);
		ft_memset(str, &str[1], strlen(str));
	}
}

static void print_rigth(char *str, t_struct *flags)
{

}

void	print_decimal(t_struct *flags, int64_t n)
{
	char *str;

	str = ft_itoa(n);
	if (flags->minus == 1)
        print_left(str, flags);
    else
        print_right(str, flags);
}
