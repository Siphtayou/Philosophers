/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agilles <agilles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 18:08:24 by agilles           #+#    #+#             */
/*   Updated: 2024/06/26 18:38:37 by agilles          ###   ########.fr       */
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
			return (print_action("Die", philos[i].id, philos[i]), 1);
			// print_action("Die\n", philos[i].id);
			// return (printf("[%ld ms] ***Stop Because Philo [%d] Die***\n", get_current_time(), philos[i].id));
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
	*philos[0].dead = 1;
	red();
	return (printf("***Stop Because All Ate***\n"));
}
