/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_eat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agilles <agilles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 16:03:28 by agilles           #+#    #+#             */
/*   Updated: 2024/08/27 16:08:07 by agilles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

void	eat_suite(t_philo *philo)
{
	pthread_mutex_lock(philo->dead_lock);
	if (*philo->dead == 1)
	{
		pthread_mutex_unlock(philo->dead_lock);
		pthread_mutex_unlock(philo->l_fork);
		pthread_mutex_unlock(philo->r_fork);
		return (print_action("Dropped Fork", philo->id, *philo));
	}
	pthread_mutex_unlock(philo->dead_lock);
	print_action("has take a Fork", philo->id, *philo);
	pthread_mutex_lock(philo->dead_lock);
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

void	philo_eat(t_philo *philo)
{
	pthread_mutex_lock(philo->dead_lock);
	if (*philo->dead == 1)
	{
		pthread_mutex_unlock(philo->dead_lock);
		return ;
	}
	pthread_mutex_unlock(philo->dead_lock);
	pthread_mutex_lock(philo->l_fork);
	print_action("has take a Fork", philo->id, *philo);
	pthread_mutex_lock(philo->dead_lock);
	if (philo->num_philo == 1)
	{
		ft_usleep(philo->time_to_die);
		*philo->dead = 1;
		pthread_mutex_unlock(philo->dead_lock);
		pthread_mutex_unlock(philo->l_fork);
		return ;
	}
	pthread_mutex_unlock(philo->dead_lock);
	pthread_mutex_lock(philo->r_fork);
	eat_suite(philo);
}

/***		PAIR EAT		***/

void	eat_pair_suite(t_philo *philo)
{
	pthread_mutex_lock(philo->dead_lock);
	if (*philo->dead == 1)
	{
		pthread_mutex_unlock(philo->dead_lock);
		pthread_mutex_unlock(philo->r_fork);
		pthread_mutex_unlock(philo->l_fork);
		return (print_action("Dropped Fork", philo->id, *philo));
	}
	pthread_mutex_unlock(philo->dead_lock);
	print_action("has take a Fork", philo->id, *philo);
	pthread_mutex_lock(philo->dead_lock);
	philo->last_meal = get_current_time();
	pthread_mutex_unlock(philo->dead_lock);
	print_action("start to eat", philo->id, *philo);
	pthread_mutex_lock(philo->meal_lock);
	if (philo->meals_eaten != INT_MAX)
		philo->meals_eaten++;
	pthread_mutex_unlock(philo->meal_lock);
	ft_usleep(philo->time_to_eat);
	pthread_mutex_unlock(philo->r_fork);
	pthread_mutex_unlock(philo->l_fork);
}

void	philo_pair_eat(t_philo *philo)
{
	pthread_mutex_lock(philo->dead_lock);
	if (*philo->dead == 1)
	{
		pthread_mutex_unlock(philo->dead_lock);
		return ;
	}
	pthread_mutex_unlock(philo->dead_lock);
	pthread_mutex_lock(philo->r_fork);
	print_action("has take a Fork", philo->id, *philo);
	pthread_mutex_lock(philo->dead_lock);
	if (philo->num_philo == 1)
	{
		ft_usleep(philo->time_to_die);
		*philo->dead = 1;
		pthread_mutex_unlock(philo->dead_lock);
		pthread_mutex_unlock(philo->r_fork);
		return ;
	}
	pthread_mutex_unlock(philo->dead_lock);
	pthread_mutex_lock(philo->l_fork);
	eat_pair_suite(philo);
}
