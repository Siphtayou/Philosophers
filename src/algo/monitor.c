/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agilles <agilles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 18:08:24 by agilles           #+#    #+#             */
/*   Updated: 2024/06/25 19:38:56 by agilles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

void	*monitor(void *ptr)
{
	t_philo	*philo;

	philo = (t_philo *)ptr;
	printf("alors %p\n", philo);
	while (1)
	{
		printf("fils de pute répond non ?\n");
		if (check_dead(philo) || check_all_ate(philo))
			break ;
	}
	printf("ah vraiment mais pq ca tourne alors ?\n");
	return (ptr);
}

int	check_dead(t_philo *philos)
{
	int		i;

	i = -1;
	while (++i < philos[0].num_philo)
	{
		if (get_current_time() - philos[i].last_meal > philos[i].time_to_die)
			return (1);
	}
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
		if (philos[i].meals_eaten < philos[i].num_times_to_eat)
			return (0);
	}
	return (1);
}
