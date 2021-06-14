/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdong <qdong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 14:26:12 by qdong             #+#    #+#             */
/*   Updated: 2021/06/14 19:48:41 by qdong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int		out_char;

void sigusr1(int signo)
{
    (void)signo;
	int	counter;

	out_char += counter;
    counter /= 2;
	if (counter == 0)
	{
		write(STDOUT_FILENO, &out_char, 1);
		out_char = 0;
		counter = 128;
	}
}

void sigusr2(int signo)
{
    (void)signo;
	int	counter;

	counter /= 2;
	if (counter == 0)
	{
		write(STDOUT_FILENO, &out_char, 1);
		out_char = 0;
		counter = 128;
	}
}

int main()
{
	int	counter;

	out_char = 0;
	counter = 128;
	ft_putstr("pid: ");
	ft_putnbr(getpid());
	ft_putchar('\n');
	while(1)
	{
		signal(SIGUSR1, sigusr1);
		signal(SIGUSR2, sigusr2);
		pause();
	}
}
