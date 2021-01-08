/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_poiter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdong <qdong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 12:19:46 by qdong             #+#    #+#             */
/*   Updated: 2021/01/08 22:36:44 by qdong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void print_left(char *str, t_struct *flags)
{
	int len;
	int i;

	len = 0;
	if (!(i = 0) && str[0] == '-')
	{
		ft_memmove(str, &str[1], ft_strlen(str));
		len += write(1, " ", 1);
	}
	while(i < flags->accuracy - ft_strlen(str))
	{
		len += write(1, "0", 1);
		i++;
	}
	len += write(1, str, ft_strlen(str) - ((str[0] == '-') ? 1 : 0));
	i = 0;
	while (i < flags->width - len)
		i += write(1, " ", 1);
	flags->len += len + i;
}

static void right_dot_accless(char *str, t_struct *flags, int len)
{
	int i;

	i = 0;
	while (i < flags->width - ft_strlen(str))
			i += write(1, " ", 1);
	len += write(1, str, ft_strlen(str));

	flags->len += len + i;
}

static void right_dot(char *str, t_struct *flags, int len)
{
	int t;
	int i;

	if (!(i = 0) && ((flags->accuracy > ft_strlen(str) && str[0] != '-')
		|| (flags->accuracy > ft_strlen(str) - 1 && str[0] == '-')))
	{
		if (str[0] == '-')
			t = flags->accuracy - (ft_strlen(str) - 1);
		else
			t = flags->accuracy - ft_strlen(str);
		while (i < flags->width - ft_strlen(str) - t)
			i += write(1, " ", 1);
		if (str[0] == '-')
		{
			i += write(1, "-", 1);
			ft_memmove(str, &str[1], ft_strlen(str));
		}
		len += i;
		i = 0;
		while(i < t)
			i += write(1, "0", 1);
		len += write(1, str, ft_strlen(str));
	}
	else
		right_dot_accless(str, flags, len);
	flags->len += len + i;
}

static void print_right(char *str, t_struct *flags)
{
	int len;
	int i;

	len = 0;
	if (!(i = 0) && flags->dot)
		right_dot(str, flags, len);
	else
	{
		if (flags->width > ft_strlen(str))
		{
			if (str[0] == '-' && flags->zero)
			{
				len += write(1, "-", 1);
				ft_memmove(str, &str[1], ft_strlen(str));
			}
			while (i < flags->width - ft_strlen(str) - len)
			{
				if (flags->zero)
					i += write(1, "0", 1);
				else
					i += write(1, " ", 1);
			}
		}
		len += write(1, str, ft_strlen(str));
	}
	flags->len += len + i;
}

void	print_poiter(int n, t_struct *flags)
{
	int *str;

	str = itoa_base(n, flags);
	// if (n == 0 && flags->dot && flags->accuracy == 0)
	// 	ft_memmove(str, &str[1], 1);
	if (flags->minus == 1)
		print_left(str, flags);
	else
		print_right(str, flags);
}
