/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdong <qdong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 12:19:46 by qdong             #+#    #+#             */
/*   Updated: 2021/01/10 20:20:48 by qdong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		print_left(char *str, t_struct *flags)
{
	int			len;
	int			i;

	len = 0;
	if (flags->type == 'p')
		len = write(1, "0x", 2);
	i = 0;
	while (i < flags->accuracy - ft_strlen(str))
		i += write(1, "0", 1);
	len += write(1, str, ft_strlen(str));
	len += i;
	i = 0;
	while (i < flags->width - len)
		i += write(1, " ", 1);
	flags->len += len + i;
}

static void		right_dot_accless(char *str, t_struct *flags, int len)
{
	int			i;
	int			t;

	t = 0;
	if (flags->type == 'p')
		t = 2;
	i = 0;
	while (i < flags->width - ft_strlen(str) - t)
		i += write(1, " ", 1);
	if (flags->type == 'p')
		i += write(1, "0x", 2);
	len += write(1, str, ft_strlen(str));
	flags->len += len + i;
}

static void		right_dot(char *str, t_struct *flags, int len)
{
	int			t;
	int			i;

	t = 0;
	if (!(i = 0) && ((flags->accuracy > ft_strlen(str))))
	{
		if (flags->accuracy > ft_strlen(str))
			t = flags->accuracy - ft_strlen(str);
		else if (flags->type == 'p')
			t = 2;
		while (i < flags->width - ft_strlen(str) - t)
			i += write(1, " ", 1);
		if (flags->type == 'p')
			i += write(1, "0x", 2);
		len += i;
		i = 0;
		while (i < t)
			i += write(1, "0", 1);
		len += write(1, str, ft_strlen(str));
	}
	else
		right_dot_accless(str, flags, len);
	flags->len += len + i;
}

static void		print_right(char *str, t_struct *flags)
{
	int			len;
	int			i;
	int			t;

	len = 0;
	if (!(t = 0) && flags->type == 'p')
		t = 2;
	if (!(i = 0) && flags->dot)
		right_dot(str, flags, len);
	else
	{
		if (flags->width > ft_strlen(str) - t)
		{
			while (i < flags->width - ft_strlen(str) - t)
				if (flags->zero && flags->type != 'p')
					i += write(1, "0", 1);
				else
					i += write(1, " ", 1);
		}
		if (flags->type == 'p')
			i += write(1, "0x", 2);
		len += write(1, str, ft_strlen(str));
	}
	flags->len += len + i;
}

void			print_pointer(unsigned long long int n, t_struct *flags)
{
	char		*str;

	if (flags->type == 'X')
		str = itoa_base2(n, "0123456789ABCDEF");
	else
		str = itoa_base2(n, "0123456789abcdef");
	if (n == 0 && flags->dot && flags->accuracy == 0)
		str[0] = '\0';
	if (flags->minus == 1)
		print_left(str, flags);
	else
		print_right(str, flags);
	free(str);
	str = NULL;
}
