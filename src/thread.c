/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agilles <agilles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 16:28:43 by agilles           #+#    #+#             */
/*   Updated: 2024/06/24 18:07:19 by agilles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	thread_create(t_program *prog)
{
	pthread_t	observer;
	int			i;

	if (pthread_create(&observer, NULL, &monitor, &prog) != 0)
	{
		thread_creation_err();
		destroy_all(); // TODO
	}
	i = -1;
	while (++i < prog->philos[0].num_philo)
	{
		if (pthread_create(&prog->philos[i].thread, NULL, &routine, &prog->philos[i]) != 0)
		{
			thread_creation_err();
			destroy_all(); // TODO
		}
	}
	if (pthread_join(&observer, NULL) != 0)
	{
		thread_join_err();
		destroy_all(); // TODO
	}
	i = -1;
	while (++i < prog->philos[0].num_philo)
	{
		if (pthread_join(&prog->philos[i].thread, NULL) != 0)
		{
			thread_join_err();
			destroy_all(); // TODO
		}
	}
	return (0);

}
