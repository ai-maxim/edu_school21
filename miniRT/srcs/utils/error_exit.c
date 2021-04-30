/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdong <qdong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 16:57:58 by qdong             #+#    #+#             */
/*   Updated: 2021/04/22 19:52:08 by qdong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	ft_perror(char *s)
{
	int	i;

	i = 0;
	if (s)
	{
		while (s[i])
			i++;
		write(1, s, i);
	}
	exit(-1);
	return (1);
}

void	error_exit(int code)
{
	if (code == -1)
		write(1, "ERROR: invalid imput\n", 21);
	exit(code);
}

char	error_color(char **array)
{
	(void)array;
	return (ft_perror(ERR5));
}

void	ft_exit(char *s)
{
	printf("%s\n", s);
	exit(1);
}

char	error_invalid_file(int argc, char **argv)
{
	int	tmp;

	(void)argc;
	tmp = ft_strlen(argv[1]);
	if (tmp < 4)
		return (ft_perror(ERR4));
	if ((ft_isascii(argv[1][tmp - 4]) == 0) || (argv[1][tmp - 3] != '.' &&
		argv[1][tmp - 2] != 'r' && argv[1][tmp - 1] != 't'))
		return (ft_perror(ERR4));
	return (0);
}
