/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agilles <agilles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 16:28:43 by agilles           #+#    #+#             */
/*   Updated: 2024/08/14 19:12:34 by agilles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	create_philo(t_program *p, int i, pthread_mutex_t *forks)
{
	if ((pthread_create(&p->philos[i].thread, NULL, &routine, &p->philos[i])))
	{
		thread_creation_err();
		destroy_all(p, forks);
	}
}

int	thread_create(t_program *prog, pthread_mutex_t *forks, int i)
{
	pthread_t	observer;

	if (pthread_create(&observer, NULL, &monitor, prog->philos) != 0)
	{
		thread_creation_err();
		destroy_all(prog, forks);
	}
	i = -1;
	while (++i < prog->philos[0].num_philo)
		create_philo(prog, i, forks);
	if (pthread_join(observer, NULL) != 0)
	{
		thread_join_err();
		destroy_all(prog, forks);
	}
	i = -1;
	while (++i < prog->philos[0].num_philo)
	{
		if (pthread_join(prog->philos[i].thread, NULL) != 0)
		{
			thread_join_err();
			destroy_all(prog, forks);
		}
	}
	return (0);
}

void	destroy_all(t_program *prog, pthread_mutex_t *forks)
{
	t_philo	*philos;
	int		i;

	i = -1;
	philos = (t_philo *)prog->philos;
	pthread_mutex_destroy(&prog->dead_lock);
	pthread_mutex_destroy(&prog->write_lock);
	pthread_mutex_destroy(&prog->meal_lock);
	while (++i < philos[0].num_philo)
	{
		pthread_mutex_destroy(&forks[i]);
	}
}
