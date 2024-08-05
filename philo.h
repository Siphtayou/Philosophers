/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agilles <agilles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 16:53:26 by agilles           #+#    #+#             */
/*   Updated: 2024/08/05 10:44:40 by agilles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <pthread.h>
# include <sys/time.h>
# include <unistd.h>
# include <stdio.h>
# include <limits.h>
# include "printf_libft/ft_printf.h"

#define MAX_PHILO 300

typedef struct	s_philo
{
	pthread_t		thread;
	int				id;
	int				eating;
	int				meals_eaten;
	long				last_meal;
	long				time_to_die;
	long				time_to_eat;
	long				time_to_sleep;
	int				num_times_to_eat;
	int				num_philo;
	int				*dead;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*write_lock;
	pthread_mutex_t	*dead_lock;
	pthread_mutex_t	*meal_lock;
}						t_philo;

typedef struct s_program
{
	int				dead_flag;
	pthread_mutex_t	dead_lock;
	pthread_mutex_t	meal_lock;
	pthread_mutex_t	write_lock;
	t_philo			*philos;
}					t_program;

/**		INIT		**/
void	init_prog(t_program *prog, t_philo	*philos);
void	init_fork(pthread_mutex_t *fork, int philo_num);
void	init_philo(t_philo *philo, pthread_mutex_t *fork, t_program *prog,
			char **av);

/**		ERROR		**/
int		is_arg_err(int ac, char **av);
int		ft_isdigit(int n);

/**		ERROR MSG	**/
void	arg_err(void);
void	thread_creation_err(void);
void	thread_join_err(void);
void	print_info(t_program *prog, char **av);

/**		UTILS		**/
long	philo_atol(const char *nb);
int		ft_atoi(const char *nb);
long	get_current_time(void);
int		ft_usleep(size_t milliseconds);

/**		THREAD		**/
int		thread_create(t_program *prog, pthread_mutex_t *forks);
void	destroy_all(t_program *prog, pthread_mutex_t *forks);
void	*monitor(void *ptr);

/**		PHILO		**/
int		dead_loop(t_philo *philo);
void	*routine(void *ptr);
void	print_action(char *str, int id,t_philo philo);
void	philo_eat(t_philo *philo);
void	philo_sleep(t_philo *philo);
void	philo_think(t_philo *philo);

/**		MONITOR		**/
void	*monitor(void *ptr);
int		check_dead(t_philo *philos);
int		check_all_ate(t_philo *philos);

/**		COLOR		**/
void	chose_color(char *str);

void	red(void);
void	yellow(void);
void	purple(void);
void	cyan(void);
void	magenta(void);
void	blue(void);
void	reset(void);

#endif
