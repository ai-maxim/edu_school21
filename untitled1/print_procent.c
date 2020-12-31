/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_procent.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdong <qdong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 12:19:55 by qdong             #+#    #+#             */
/*   Updated: 2020/12/28 12:19:57 by qdong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int     ft_prochent(t_struct flags)
{
    int count;

    count = 0;
    if(flags.minus == 1)
        count += ft_putstr_chec("%", 1);
    count += ft_done_width(flags.width, 1, flags.zero);
    if(flags.minus = 0)
        count += ft_putstr_chec("%", 1);
    return (count);
}
