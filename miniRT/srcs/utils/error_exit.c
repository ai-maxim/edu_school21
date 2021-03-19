/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdong <qdong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 16:57:58 by qdong             #+#    #+#             */
/*   Updated: 2021/03/14 20:53:44 by qdong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	error_exit(int code)
{
	if (code == -1)
		write(1, "ERROR: memory allocation error", 30);
	// if (code == 1)
	// 	write(1, "ERROR: memory allocation error", 30);
	exit(code);
}
