/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mouk <oel-mouk@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 20:49:57 by oel-mouk          #+#    #+#             */
/*   Updated: 2024/12/14 22:28:47 by oel-mouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	main(int ac, char **av)
{
	pthread_mutex_t	*forks;
	t_philo			*philos;
	t_args			args;
	int				i;

	if (check_args(ac, av) == -1)
		return (1);
	save_args(&args, ac, av);
	i = -1;
	forks = malloc(sizeof(pthread_mutex_t) * args.philos_count);
	philos = malloc(sizeof(t_philo) * args.philos_count);
	while (++i < args.philos_count)
		if (pthread_mutex_init(&forks[i], NULL) != 0)
			ft_error("Creation of forks mutexes failed.");
	if (create_threads(philos, &args, forks) == -1)
		return (1);
	free(forks);
	free(philos);
	return (0);
}
