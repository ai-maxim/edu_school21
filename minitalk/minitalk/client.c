/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdong <qdong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 14:25:50 by qdong             #+#    #+#             */
/*   Updated: 2021/06/16 19:22:09 by qdong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_message(pid_t pid, char *mail)
{
	int	count;
	int	i;

	i = 0;
	while (mail[i])
	{
		count = 128;
		while (count >= 1)
		{
			if (count & mail[i])
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			count /= 2;
			usleep(100);
		}
		i++;
	}
}

int	main(int argc, char *argv[])
{
	pid_t	pid;

	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		send_message(pid, argv[2]);
	}
	else
		write(1, "ERROR\n", 8);
	return (0);
}
