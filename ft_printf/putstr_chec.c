/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putstr_chec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdong <qdong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 19:26:11 by qdong             #+#    #+#             */
/*   Updated: 2021/01/10 19:33:30 by qdong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		putstr_chec(char *str, int chec)
{
	int count;

	count = 0;
	while (str[count] && count < chec)
		ft_putchar(str[count++]);
	return (count);
}
