/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agilles <agilles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 18:08:22 by agilles           #+#    #+#             */
/*   Updated: 2024/08/27 16:06:33 by agilles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

void	*routine(void *ptr)
{
	t_philo	*philo;

	philo = (t_philo *)ptr;
	if (philo->id % 2 == 0)
		ft_usleep(1);
	while (!dead_loop(philo))
	{
		pthread_mutex_lock(philo->dead_lock);
		if (*philo->dead != 1)
		{
			pthread_mutex_unlock(philo->dead_lock);
			if (philo->id % 2)
				philo_eat(philo);
			else
				philo_pair_eat(philo);
		}
		else
			pthread_mutex_unlock(philo->dead_lock);
		philo_sleep(philo);
		philo_think(philo);
	}
	return (ptr);
}

void	philo_sleep(t_philo *philo)
{
	pthread_mutex_lock(philo->dead_lock);
	if (*philo->dead == 1)
	{
		pthread_mutex_unlock(philo->dead_lock);
		return ;
	}
	pthread_mutex_unlock(philo->dead_lock);
	print_action("is sleeping", philo->id, *philo);
	ft_usleep(philo->time_to_sleep);
}

void	philo_think(t_philo *philo)
{
	pthread_mutex_lock(philo->dead_lock);
	if (*philo->dead == 1)
	{
		pthread_mutex_unlock(philo->dead_lock);
		return ;
	}
	pthread_mutex_unlock(philo->dead_lock);
	print_action("is thinking", philo->id, *philo);
}
