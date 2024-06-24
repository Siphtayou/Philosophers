/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agilles <agilles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 16:53:17 by agilles           #+#    #+#             */
/*   Updated: 2024/06/24 17:52:42 by agilles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_program		prog;
	t_philo			philos[MAX_PHILO];
	pthread_mutex_t	forks[MAX_PHILO];

	if (is_arg_err(ac, av))
		return (1);
	init_prog(&prog, philos);
	init_fork(forks, ft_atoi(av[1]));
	init_philo(philos, forks, &prog, av);
	thread_create(&prog);
	print_info(&prog, av);
	return (0);
}
