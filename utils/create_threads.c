/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_threads.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mouk <oel-mouk@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 20:50:26 by oel-mouk          #+#    #+#             */
/*   Updated: 2024/12/16 02:50:34 by oel-mouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	init_philo(t_philo *philos, t_args *args, pthread_mutex_t *forks)
{
	pthread_mutex_t	*print;
	int				i;

	i = -1;
	print = malloc(sizeof(pthread_mutex_t));
	if (pthread_mutex_init(print, NULL)
		|| pthread_mutex_init(&philos->eat_mutex, NULL))
		return (1);
	while (++i < args->philos_count)
	{
		philos[i].args = args;
		philos[i].id = (i + 1);
		philos[i].left_fork = philos[i].id - 1;
		philos[i].right_fork = philos[i].id % args->philos_count;
		philos[i].eat_count = 0;
		philos[i].start_eat_time = now();
		philos[i].last_meal_time = now();
		philos[i].forks = forks;
		philos[i].print = print;
		philos[i].eat_mutex = philos->eat_mutex;
	}
	return (0);
}

int	create_threads(t_philo *philos, t_args *args, pthread_mutex_t *forks)
{
	int	i;

	if (init_philo(philos, args, forks))
		ft_error("Creation of meals mutexes failed.");
	i = -1;
	while (++i < args->philos_count)
	{
		if (pthread_create(&philos[i].thread, NULL, &simulation, &philos[i]))
			return (ft_error("Creation of threads failed"));
		usleep(1000);
	}
	check_end_simulation(philos);
	return (0);
}
