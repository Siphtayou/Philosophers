/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agilles <agilles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 18:38:11 by agilles           #+#    #+#             */
/*   Updated: 2024/08/14 18:56:25 by agilles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	init_prog(t_program *prog, t_philo	*philos)
{
	prog->dead_flag = 0;
	prog->philos = philos;
	pthread_mutex_init(&prog->dead_lock, NULL);
	pthread_mutex_init(&prog->meal_lock, NULL);
	pthread_mutex_init(&prog->write_lock, NULL);
}

void	init_fork(pthread_mutex_t *fork, int philo_num)
{
	int	i;

	i = 0;
	while (i < philo_num)
	{
		pthread_mutex_init(&fork[i], NULL);
		i++;
	}
}

void	init_philo(t_philo *philo, pthread_mutex_t *fork, t_program *prog,
			char **av)
{
	int	i;

	i = -1;
	while (++i < ft_atoi(av[1]))
	{
		philo[i].id = i + 1;
		philo[i].eating = 0;
		philo[i].meals_eaten = 0;
		philo[i].last_meal = get_current_time();
		philo[i].num_philo = philo_atol(av[1]);
		philo[i].time_to_die = philo_atol(av[2]);
		philo[i].time_to_eat = philo_atol(av[3]);
		philo[i].time_to_sleep = philo_atol(av[4]);
		philo[i].num_times_to_eat = -1;
		philo[i].dead = &prog->dead_flag;
		philo[i].dead_lock = &prog->dead_lock;
		philo[i].write_lock = &prog->write_lock;
		philo[i].meal_lock = &prog->meal_lock;
		if (av[5])
			philo[i].num_times_to_eat = philo_atol(av[5]);
		philo[i].r_fork = &fork[i];
		philo[i].l_fork = &fork[i - 1];
		if (i == 0)
			philo[i].l_fork = &fork[philo_atol(av[1]) - 1];
	}
}

/*
void	init_philo(t_philo *philo, pthread_mutex_t *fork, t_program *prog,
			char **av)
{
	int	i;

	i = -1;
	while (++i < ft_atoi(av[1]))
	{
		philo[i].id = i + 1;
		philo[i].eating = 0;
		philo[i].meals_eaten = 0;
		philo[i].last_meal = get_current_time();
		philo[i].num_philo = philo_atol(av[1]);
		philo[i].time_to_die = philo_atol(av[2]);
		philo[i].time_to_eat = philo_atol(av[3]);
		philo[i].time_to_sleep = philo_atol(av[4]);
		philo[i].num_times_to_eat = -1;
		philo[i].dead = &prog->dead_flag;
		philo[i].dead_lock = &prog->dead_lock;
		philo[i].write_lock = &prog->write_lock;
		philo[i].meal_lock = &prog->meal_lock;
		if (av[5])
			philo[i].num_times_to_eat = philo_atol(av[5]);
		philo[i].r_fork = &fork[i];
		if (i == 0)
			philo[i].l_fork = &fork[philo_atol(av[1]) - 1];
		else
			philo[i].l_fork = &fork[i - 1];
	}
}
*/
