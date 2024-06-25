/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agilles <agilles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 18:08:22 by agilles           #+#    #+#             */
/*   Updated: 2024/06/25 19:35:51 by agilles          ###   ########.fr       */
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
		philo_eat(philo); //TO FINISH
		philo_sleep(philo);
		philo_think(philo);
		printf("Philo %d eat %d Spagout\n", philo->id, philo->meals_eaten);
	}
	return (ptr);

}

void	print_action(char *str, int id)
{
	printf("[%ld ms] Philo %d %s.\n", get_current_time(), id, str);
}

void	philo_eat(t_philo *philo)
{
	pthread_mutex_lock(philo->l_fork);
	print_action("has take a Fork", philo->id);
	if (philo->num_philo == 1)
	{
		ft_usleep(philo->time_to_die);
		pthread_mutex_unlock(philo->l_fork);
		return ;
	}
	pthread_mutex_lock(philo->r_fork);
	print_action("has take a Fork", philo->id);
	philo->last_meal = get_current_time();
	print_action("start to eat", philo->id);
	if (philo->meals_eaten != INT_MAX)
		philo->meals_eaten++;
	ft_usleep(philo->time_to_eat);
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
}

void	philo_sleep(t_philo *philo)
{
	print_action("is sleeping", philo->id);
	ft_usleep(philo->time_to_sleep);
}

void	philo_think(t_philo *philo)
{
	print_action("is thinking", philo->id);
}
