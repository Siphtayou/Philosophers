/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agilles <agilles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 18:08:22 by agilles           #+#    #+#             */
/*   Updated: 2024/06/24 18:28:00 by agilles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

int	dead_loop(t_philo *philo)
{
	pthread_mutex_lock(philo->dead);
	if (philo->dead == 1)
		return (pthread_mutex_unlock(philo->dead), 1);
	pthread_mutex_unlock(philo->dead);
	return (0);
}

void	*routine(void *ptr)
{
	t_philo	*philo;

	philo = (t_philo *)ptr;
	if (philo->id % 2 == 0)
		ft_usleep(1);
	while (!dead_loop(philo))
	{
		philo_eat(); //TODO
		philo_sleep(); //TODO
		philo_think(); //TODO
	}
	return (ptr);

}



