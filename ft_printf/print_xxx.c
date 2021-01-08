/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_xxx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdong <qdong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 12:20:13 by qdong             #+#    #+#             */
/*   Updated: 2021/01/08 22:09:48 by qdong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void print_left(char *str, t_struct *flags)
{
	int len;
	int i;

	len = 0;
	i = 0;
	len += write(1, "0x", 2);
	while(i < flags->accuracy - ft_strlen(str))
	{
		len += write(1, "0", 1);
		i++;
	}
	len += write(1, str, ft_strlen(str));
	i = 0;
	while (i < flags->width - len)
		i += write(1, " ", 1);
	flags->len += len + i;
}

static void right_dot_accless(char *str, t_struct *flags, int len)
{
	int i;

	i = 0;
	len += write(1, "0x", 2);
	while (i < flags->width - ft_strlen(str))
			i += write(1, " ", 1);
	len += write(1, str, ft_strlen(str));

	flags->len += len + i;
}

// static void right_dot(char *str, t_struct *flags, int len)
// {
// 	int t;
// 	int i;

// 	len += write(1, "0x", 2);
// 	if (!(i = 0) && ((flags->accuracy > ft_strlen(str))
// 		|| (flags->accuracy > ft_strlen(str) - 1))
// 	{
// 		len += i;
// 		i = 0;
// 		while(i < t)
// 			i += write(1, "0", 1);
// 		len += write(1, str, ft_strlen(str));
// 	}
// 	else
// 		right_dot_accless(str, flags, len);
// 	flags->len += len + i;
// }

// static void print_right(char *str, t_struct *flags)
// {

// }

void	print_xxx(int n, t_struct *flags)
{
	int *str;

	str = itoa_base(n, flags);
	if (n == 0 && flags->dot && flags->accuracy == 0)
		ft_memmove(str, &str[1], 1);
	if (flags->minus == 1)
		print_left(str, flags);
	else
		print_right(str, flags);
}
