/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdong <qdong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 14:26:12 by qdong             #+#    #+#             */
/*   Updated: 2021/06/16 19:15:53 by qdong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_data	g_data;

void	sigusr1(int signo)
{
	(void)signo;
	g_data.out_char += g_data.count;
	g_data.count /= 2;
	if (g_data.count == 0)
	{
		write(1, &g_data.out_char, 1);
		g_data.out_char = 0;
		g_data.count = 128;
	}
}

void	sigusr2(int signo)
{
	(void)signo;
	g_data.count /= 2;
	if (g_data.count == 0)
	{
		write(1, &g_data.out_char, 1);
		g_data.out_char = 0;
		g_data.count = 128;
	}
}

int	main(void)
{
	struct sigaction	one;
	struct sigaction	two;

	one.sa_handler = sigusr1;
	two.sa_handler = sigusr2;
	g_data.count = 128;
	g_data.out_char = 0;
	ft_putstr("pid: ");
	ft_putnbr(getpid());
	ft_putchar('\n');
	while (1)
	{
		sigaction(SIGUSR1, &one, NULL);
		sigaction(SIGUSR2, &two, NULL);
		pause();
	}
}
