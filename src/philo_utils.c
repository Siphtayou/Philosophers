/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agilles <agilles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 16:31:41 by agilles           #+#    #+#             */
/*   Updated: 2024/06/24 18:14:38 by agilles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

long	philo_atol(const char *nb)
{
	long	res;
	int		s;
	int		i;

	res = 0;
	s = 1;
	i = 0;
	while (nb[i] == 32 || nb[i] == 9 || nb[i] == 12
		|| nb[i] == 10 || nb[i] == 11 || nb[i] == 13)
		i++;
	if (nb[i] == '-')
	{
		s = -1;
		i++;
		if (nb[i] < '0' || nb[i] > '9')
			return (0);
	}
	if (nb[i] == '+')
		i++;
	while (nb[i] >= 48 && nb[i] <= 57)
	{
		res = res * 10 + nb[i] - '0';
		i++;
	}
	return (res * s);
}

int	ft_atoi(const char *nb)
{
	int	i;
	int	s;
	int	res;

	res = 0;
	s = 1;
	i = 0;
	while (nb[i] == 32 || nb[i] == 9 || nb[i] == 12
		|| nb[i] == 10 || nb[i] == 11 || nb[i] == 13)
		i++;
	if (nb[i] == '-')
	{
		s = -1;
		i++;
		if (nb[i] < '0' || nb[i] > '9')
			return (0);
	}
	if (nb[i] == '+')
		i++;
	while (nb[i] >= 48 && nb[i] <= 57)
	{
		res = res * 10 + nb[i] - '0';
		i++;
	}
	return (res * s);
}

long	get_current_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		write(2, "gettimeofday() error\n", 22);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

int	ft_usleep(size_t milliseconds)
{
	size_t	start;

	start = get_current_time();
	while ((get_current_time() - start) < milliseconds)
		usleep(500);
	return (0);
}
