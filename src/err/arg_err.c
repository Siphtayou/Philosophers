/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_err.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agilles <agilles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 17:47:44 by agilles           #+#    #+#             */
/*   Updated: 2024/08/05 10:30:08 by agilles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

void	arg_err(void)
{
	printf("===ARGUMENT ERROR===\n");
	printf("\nPlease call Philo like this :\n");
	printf("./philo 5 800 200 200 7\n\n");
	printf("5 - The number of philosophers (200 max)\n");
	printf("800 - The time a philosopher will die if he doesn't eat\n");
	printf("200 - The time it takes a philosopher to eat\n");
	printf("200 - The time it takes a philosopher to sleep\n\n");
	printf("=== OPTIONAL ===\n");
	printf("7 - Number of times");
	printf(" all the philosophers need to eat before terminating the program\n");
}

void	thread_creation_err(void)
{
	printf("***\tThread Creation Error\t***\n***\tPlease try again\t***\n");
}

void	thread_join_err(void)
{
	printf("***\tThread Join Error\t***\n***\tPlease try again\t***\n");
}
