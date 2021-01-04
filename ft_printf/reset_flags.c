/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_flags.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdong <qdong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 12:18:46 by qdong             #+#    #+#             */
/*   Updated: 2020/12/29 13:37:42 by qdong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	reset_flags(t_struct *flags)
{
	flags->minus = 0;
	flags->zero = 0;
	flags->dot = 0;
	flags->accuracy = 0;
	flags->width = 0;
	flags->accuracy_specified = 0;
	flags->accuracy = 0;
	flags->type = 0;
}
