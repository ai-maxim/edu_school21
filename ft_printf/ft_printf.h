/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdong <qdong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 12:09:27 by qdong             #+#    #+#             */
/*   Updated: 2021/01/08 22:00:13 by qdong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"

# include <stdint.h>
# include <stdio.h>
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_struct
{
	int		i;
	int		len;

	int		minus;
	int		zero;
	int		dot;
	int		accuracy;
	int		width;
	int		type;
	int		accuracy_specified;

}			t_struct;

void					flag(char *format, t_struct *flags);
int						width(char *format, t_struct *flags, va_list *ap);
int						accuracy(char *format, t_struct *flags, va_list *ap);
int						pars_modifiers(char *format, t_struct *flags, va_list *ap);
int						parsers(char *format, t_struct *flags, va_list *ap);
void					ft_printing(t_struct *data, va_list *ap);
void					reset_flags(t_struct *flags);
int						ft_strlen(const char *str);
int						ft_printf(const char *, ...);

char			*ft_strchr(const char *s, int c);
int				ft_putchar(int c);
int				ft_putstr_chec(char *str, int chec);
void			ft_putchar_fd(char c, int fd);
int				ft_done_width(int width, int minus, int zero);
int				ft_done_width(int width, int minus, int zero);
char			*chec_type(char *format, t_struct *flags);
char			*itoa_base(int64_t n, t_struct *flags);

void					print_str(char *str, t_struct *f);
void					print_char(unsigned char c, t_struct *f);
void					print_deci(int64_t n, t_struct *flags);
void					print_unsig_deci(unsigned int n, t_struct *flags);
void					print_poiter(int64_t n, t_struct *flags);
//void				print_xxx(int n, t_struct *flags);
void					print_procent(t_struct *flags);

#endif
