/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agilles <agilles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 16:47:04 by agilles           #+#    #+#             */
/*   Updated: 2024/06/24 17:50:53 by agilles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

void	print_info(t_program *prog, char **av)
{
	t_philo	philo;
	int	i;

	i = -1;
	while (++i < ft_atoi(av[1]))
	{
		philo = prog->philos[i];
		printf("Philo ID : %d\n", philo.id);
		printf("Philo eating %d\n", philo.eating);
		printf("Philo meals eat %d\n", philo.meals_eaten);
		printf("Philo last meal %ld\n", philo.last_meal);
		printf("Philo num of philo %d\n", philo.num_philo);
		printf("Philo  time to die %ld\n", philo.time_to_die);
		printf("Philo time to eat %ld\n", philo.time_to_eat);
		printf("Philo time to sleep %ld\n", philo.time_to_sleep);
		if (av[5])
			printf("Philo num time to eat %d\n", philo.num_times_to_eat);
		printf("Philo dead flag %d\n", *philo.dead);
		printf("Philo r fork %p\n", philo.r_fork);
		printf("Philo l fork %p\n", philo.l_fork);
		printf("=======================\n");
	}
}
