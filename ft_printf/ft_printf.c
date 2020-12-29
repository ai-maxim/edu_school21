/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdong <qdong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 12:09:17 by qdong             #+#    #+#             */
/*   Updated: 2020/12/28 15:43:47 by qdong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int						ft_printf(const char *format, ...)
{
	va_list			ap;
	char	*str;
	int					out;
	t_struct		*flags;

	if(!(flags = (t_struct *)malloc(sizeof(t_struct))))
		return(NULL);
	va_start(ap, format);
	if ((out = pars_str((char *)format, flags, &ap)) == -1)
		return (-1);
	str = va_arg(ap, char*);
	va_end(ap);
	return(out);
}
