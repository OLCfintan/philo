/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mouk <oel-mouk@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 20:50:54 by oel-mouk          #+#    #+#             */
/*   Updated: 2024/12/17 02:20:16 by oel-mouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	ft_min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

int	ft_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

void	*simulation(void *args)
{
	t_philo	*philo;

	philo = (t_philo *)args;
	while (1)
	{
		pthread_mutex_lock(&philo->forks[ft_min(philo->left_fork,
				philo->right_fork)]);
		ft_state(philo, 'F');
		pthread_mutex_lock(&philo->forks[ft_max(philo->left_fork,
				philo->right_fork)]);
		ft_state(philo, 'F');
		ft_state(philo, 'E');
		usleep(philo->args->sleep_time * 955);
		pthread_mutex_unlock(&philo->forks[philo->left_fork]);
		pthread_mutex_unlock(&philo->forks[philo->right_fork]);
		pthread_mutex_lock(&philo->eat_mutex);
		if (philo->args->meals_count > 0)
			philo->eat_count++;
		philo->last_meal_time = now();
		pthread_mutex_unlock(&philo->eat_mutex);
		ft_state(philo, 'S');
		usleep(philo->args->sleep_time * 985);
		ft_state(philo, 'T');
	}
	return (NULL);
}
