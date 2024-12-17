/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mouk <oel-mouk@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 20:50:31 by oel-mouk          #+#    #+#             */
/*   Updated: 2024/12/17 02:25:06 by oel-mouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	ft_perror(int ex, char *msj)
{
	while (msj && *msj)
		write(2, msj++, 1);
	exit(ex);
}

int	ft_atoi(char *s)
{
	long	x;

	x = -(*s == '-');
	x = (-(x == -1) + (x == 0)) * ((x + (*s == '-' && s)) * 10 + (*(s
					+ (*s == '-')) - 48));
	s += (*s == '-');
	while ((x >= INT_MIN && x <= INT_MAX) && s++ && (*s >= 48 && *s <= 57))
		x = (x * 10) + (-(x < 0) * (*s - 48)) + ((x > 0) * (*s - 48));
	if (*s != 0 || x < 0)
		ft_perror(1, "invalid number !!\n");
	return (x);
}
