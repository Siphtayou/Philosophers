/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agilles <agilles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 18:02:51 by agilles           #+#    #+#             */
/*   Updated: 2024/08/14 19:16:36 by agilles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	chose_color(char *str)
{
	if (!ft_strcmp("has take a Fork", str))
		yellow();
	else if (!ft_strcmp("Die", str))
		red();
	else if (!ft_strcmp("is sleeping", str))
		purple();
	else if (!ft_strcmp("is thinking", str))
		blue();
	else if (!ft_strcmp("start to eat", str))
		reset();
	else
		reset();
	return ;
}

void	magenta(void)
{
	printf("\x1B[35m");
}

void	blue(void)
{
	printf("\033[0;34m");
}

void	purple(void)
{
	printf("\033[0;35m");
}

void	reset(void)
{
	printf("\033[0m");
}
