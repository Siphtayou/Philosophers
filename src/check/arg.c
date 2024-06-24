/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agilles <agilles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 17:39:58 by agilles           #+#    #+#             */
/*   Updated: 2024/06/20 18:01:04 by agilles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

int	ft_isdigit(int n)
{
	if ((n >= 48 && n <= 57))
		return (1);
	return (0);
}

int	is_arg_err(int ac, char **av)
{
	int	i;
	int	j;

	i = 0;
	if (ac < 5 || ac > 6)
	{
		arg_err();
		return (1);
	}
	while (av[++i])
	{
		j = -1;
		while (av[i][++j])
		{
			if (!ft_isdigit(av[i][j]))
				{
					arg_err();
					return (1);
				}
		}
	}
	return (0);
}
