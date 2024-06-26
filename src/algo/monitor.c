/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agilles <agilles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 18:08:24 by agilles           #+#    #+#             */
/*   Updated: 2024/06/26 16:46:45 by agilles          ###   ########.fr       */
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
	while (++i < philos[0].num_philo)
	{
		if (get_current_time() - philos[i].last_meal > philos[i].time_to_die)
		{
			*philos[i].dead = 1;
			return (printf("***Exit by Check Dead***\n"));
		}
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
	return (printf("***Exit by All ate***\n"));
}
