/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_state.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mouk <oel-mouk@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 20:50:40 by oel-mouk          #+#    #+#             */
/*   Updated: 2024/12/13 20:50:42 by oel-mouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	ft_state(t_philo *philo, char action)
{
	size_t	timestamp;

	timestamp = now() - philo->start_eat_time;
	pthread_mutex_lock(philo->print);
	if (action == 'F')
		printf("%lu %d has taken a fork\n", timestamp, philo->id);
	else if (action == 'E')
		printf("%lu %d is eating\n", timestamp, philo->id);
	else if (action == 'S')
		printf("%lu %d is sleeping\n", timestamp, philo->id);
	else if (action == 'T')
		printf("%lu %d is thinking\n", timestamp, philo->id);
	pthread_mutex_unlock(philo->print);
}
