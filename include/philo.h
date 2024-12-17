/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mouk <oel-mouk@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 20:50:02 by oel-mouk          #+#    #+#             */
/*   Updated: 2024/12/17 02:18:11 by oel-mouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <limits.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_args
{
	int				eat_time;
	int				sleep_time;
	int				die_time;
	int				philos_count;
	int				meals_count;
}					t_args;

typedef struct s_philo
{
	pthread_t		thread;
	t_args			*args;
	int				id;
	size_t			left_fork;
	size_t			right_fork;
	size_t			eat_count;
	size_t			start_eat_time;
	size_t			last_meal_time;
	pthread_mutex_t	eat_mutex;
	pthread_mutex_t	*print;
	pthread_mutex_t	*forks;
}					t_philo;

int					ft_atoi(char *s);
void				*simulation(void *args);
int					ft_error(char *message);
int					create_threads(t_philo *philos, t_args *args,
						pthread_mutex_t *forks);
int					check_args(int ac, char **av);
void				save_args(t_args *args, int ac, char **av);
void				ft_state(t_philo *philo, char action);
void				check_end_simulation(t_philo *philos);
long				now(void);

#endif
