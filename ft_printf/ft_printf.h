/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdong <qdong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 12:09:27 by qdong             #+#    #+#             */
/*   Updated: 2020/12/28 15:39:54 by qdong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"

# include <stdio.h>
# include <stdarg.h>
# include <stdlib.h>
#include <unistd.h>

typedef struct s_struct
{
	int   i;
	int   len;
	int   fd;

	int   minus;
	int   zero;
	int   dot;
	int   star;
	int   accuracy;

	int   width;
	int   precision_specified;
	int   precision;
	int   length;

}       t_struct;

int						pars_str(char *format, t_struct *flags, va_list *ap);
void					print_str(char *str, t_struct *f);
void					ft_printing(char *str, t_struct *data);
void					ft_init_f(t_struct *flags);
size_t				ft_strlen(const char *str);
int						ft_printf(const char *, ...);


#endif
