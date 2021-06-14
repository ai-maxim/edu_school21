/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdong <qdong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 14:26:03 by qdong             #+#    #+#             */
/*   Updated: 2021/06/14 17:50:07 by qdong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

#include <unistd.h>
#include <signal.h>
#include <sys/types.h>

// typedef struct s_data
// {
// 	int out_char;
// 	int counter;
// } 				t_data;

size_t	ft_strlen(const char *str);
void	ft_putchar(char c);
void	ft_putstr(char *str);
void	ft_putnbr(int nbr);
int		check_nonprintable(char str);
int		ft_atoi(char *str);

#endif
