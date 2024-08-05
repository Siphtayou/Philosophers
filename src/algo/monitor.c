/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agilles <agilles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 18:08:24 by agilles           #+#    #+#             */
/*   Updated: 2024/08/05 14:14:30 by agilles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

void	*monitor(void *ptr)
{
	t_philo	*philo;

	philo = (t_philo *)ptr;
	while (1)
	{
		if (check_dead(philo) || check_all_ate(philo))
			break ;
	}
	return (ptr);
}

int	check_dead(t_philo *philos)
{
	int		i;

	i = -1;
	pthread_mutex_lock(philos[0].dead_lock);
	while (++i < philos[0].num_philo)
	{
		if (get_current_time() - philos[i].last_meal > philos[i].time_to_die)
		{
			*philos[i].dead = 1;
			pthread_mutex_unlock(philos[0].dead_lock);
			return (print_action("Die", philos[i].id, philos[i]), 1);
		}
	}
	pthread_mutex_unlock(philos[0].dead_lock);
	return (0);
}

int	check_all_ate(t_philo *philos)
{
	int		i;

	i = -1;
	if (philos[0].num_times_to_eat == -1)
		return (0);
	while (++i < philos[0].num_philo)
	{
		pthread_mutex_lock(philos[i].meal_lock);
		if (philos[i].meals_eaten < philos[i].num_times_to_eat)
		{
			pthread_mutex_unlock(philos[i].meal_lock);
			return (0);
		}
		pthread_mutex_unlock(philos[i].meal_lock);
	}
	pthread_mutex_lock(philos[0].dead_lock);
	*philos[0].dead = 1;
	pthread_mutex_unlock(philos[0].dead_lock);
	red();
	return (printf("***Stop Because All Ate***\n"));
}
