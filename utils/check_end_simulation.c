/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_end_simulation.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mouk <oel-mouk@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 20:50:22 by oel-mouk          #+#    #+#             */
/*   Updated: 2024/12/13 20:50:24 by oel-mouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	death(t_philo *philo)
{
	if (now() - philo->last_meal_time > (size_t)philo->args->die_time)
	{
		pthread_mutex_lock(philo->print);
		printf("%lu %d is died\n", now() - philo->start_eat_time, philo->id);
		return (-1);
	}
	return (0);
}

void	fill_cache(int *cache, int len)
{
	int	i;

	i = -1;
	while (++i < len)
		cache[i] = 0;
}

int	all_philos_eat(int *cache, int len)
{
	int	i;

	i = 0;
	while (cache[i] == 1)
		i++;
	if (i == len)
		return (1);
	return (0);
}

void	check_end_simulation(t_philo *philos)
{
	int	i;
	int	cache[255];

	i = 0;
	fill_cache(cache, philos->args->philos_count);
	while (i < philos->args->philos_count)
	{
		pthread_mutex_lock(&philos[i].eat_mutex);
		if (philos->args->meals_count > 0
			&& (philos[i].eat_count == (size_t)philos->args->meals_count))
		{
			cache[i] = 1;
			if (all_philos_eat(cache, philos->args->philos_count))
				return ;
		}
		if (death(&philos[i]) == -1)
			return ;
		pthread_mutex_unlock(&philos[i].eat_mutex);
		i++;
		if (i == philos->args->philos_count)
			i = 0;
	}
}
