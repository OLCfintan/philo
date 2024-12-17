/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mouk <oel-mouk@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 20:50:16 by oel-mouk          #+#    #+#             */
/*   Updated: 2024/12/16 02:36:24 by oel-mouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	check_args(int ac, char **av)
{
	int	i;

	i = 0;
	if (ac < 5 || ac > 6)
		return (ft_error("Incorrect number of arguments. Expected [5] or [6]"));
	while (++i < ac)
	{
		if (ft_atoi(av[i]) == 0)
			return (ft_error("Argument should not be [0]."));
	}
	if (ft_atoi(av[1]) > 200)
		return (ft_error("Maximum number of philosophers is [200]"));
	return (0);
}
