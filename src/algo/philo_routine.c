/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agilles <agilles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 18:08:22 by agilles           #+#    #+#             */
/*   Updated: 2024/08/05 14:57:37 by agilles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

int	dead_loop(t_philo *philo)
{
	pthread_mutex_lock(philo->dead_lock);
	if (*philo->dead == 1)
		return (pthread_mutex_unlock(philo->dead_lock), 1);
	pthread_mutex_unlock(philo->dead_lock);
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
		pthread_mutex_lock(philo->dead_lock);
		if (*philo->dead != 1)
		{
			pthread_mutex_unlock(philo->dead_lock);
			philo_eat(philo);
		}
		else
			pthread_mutex_unlock(philo->dead_lock);
		philo_sleep(philo);
		philo_think(philo);
	}
	return (ptr);

}

void	print_action(char *str, int id, t_philo philo)
{
	if (*philo.dead == 1 && (ft_strcmp(str, "Die")))
		return ;
	pthread_mutex_lock(philo.write_lock);
	cyan();
	printf("[%ld ms] ", get_current_time());
	chose_color(str);
	printf("Philo %d %s.\n", id, str);
	pthread_mutex_unlock(philo.write_lock);
}

void	philo_eat(t_philo *philo)
{
	if (*philo->dead == 1)
		return ;
	pthread_mutex_lock(philo->l_fork);
	print_action("has take a Fork", philo->id, *philo);
	if (philo->num_philo == 1)
	{
		ft_usleep(philo->time_to_die);
		pthread_mutex_unlock(philo->l_fork);
		return ;
	}
	pthread_mutex_lock(philo->r_fork);
	pthread_mutex_lock(philo->dead_lock);
	if (*philo->dead == 1)
	{
		pthread_mutex_unlock(philo->dead_lock);
		pthread_mutex_unlock(philo->l_fork);
		pthread_mutex_unlock(philo->r_fork);
		return (print_action("Dropped Fork", philo->id, *philo));
	}
	// pthread_mutex_unlock(philo->dead_lock);
	print_action("has take a Fork", philo->id, *philo);
	// pthread_mutex_lock(philo->dead_lock);
	philo->last_meal = get_current_time();
	pthread_mutex_unlock(philo->dead_lock);
	print_action("start to eat", philo->id, *philo);
	pthread_mutex_lock(philo->meal_lock);
	if (philo->meals_eaten != INT_MAX)
		philo->meals_eaten++;
	pthread_mutex_unlock(philo->meal_lock);
	ft_usleep(philo->time_to_eat);
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
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
