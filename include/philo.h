/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaezzem <omaezzem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 09:36:38 by omaezzem          #+#    #+#             */
/*   Updated: 2025/04/12 17:45:44 by omaezzem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <sys/time.h>

# define MAX_PHILO 200
# define MAX_MEAL  200

/* Error messages */
# define ERR_INV_N_PHILO "Error: Number of philosophers must be at least 1.\n"
# define ERR_INV_INPUT   "Error: argument must be positive integers.\n"
# define ERR_INV_MEALS   "Error: number of meals must be positive integers.\n"
# define ERR_INV_ARG     "Error: argument must be a number\n"
# define ERR_INV_NUM     "Error: argument must be less or equal to INT_MAX\n"
# define ERR_INV_ALOCATION  "Error: failed allocation\n"
# define ERR_INIT        "Error: failed initialization\n"

/* Status messages */
# define MSG_FORK "has taken a fork\n"
# define MSG_DIED "died\n"
# define MSG_EAT  "is eating\n"
# define MSG_SLP  "is sleeping\n"
# define MSG_THK  "is thinking\n"

typedef struct s_dining_table	t_dining_table;

typedef struct s_philosopher
{
	int				id;
	pthread_t		thread;
	size_t			last_meal_time;
	int				meals_eaten;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	t_dining_table	*table;
}	t_philosopher;

typedef struct s_dining_table
{
	int				philosopher_count;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				required_meals;
	int				die_flag;
	size_t			start_time;
	pthread_mutex_t	meal_lock;
	pthread_mutex_t	time_lock;
	pthread_mutex_t	print_lock;
	pthread_mutex_t	death_lock;
	pthread_mutex_t	*forks;
	t_philosopher	*philosophers;
}	t_dining_table;

/* Utilis functions */
int		ft_isdigit(char c);
void	ft_putstr_fd(char *s, int fd);
int		atoi_ph(char *str);
int		ft_to_int(char *str);
size_t	get_current_time(void);
int		ft_ph_sleep(size_t time, t_dining_table *table);

/* Input validation */
int		validinput(int ac, char **av);

/* Philosopher logic */
int		init_dining_table(t_dining_table *table, char **av, int ac);
int		bismillah(t_dining_table *table);
void	hyper(t_dining_table *table);
void	start_dining(t_philosopher *philo);
int		ft_exit_dining(t_philosopher *philo);

/* Sync functions */
void	safe_print(t_philosopher *philo, char *msg);
void	update_last_meal_time(t_philosopher *philo);
void	increment_meal_count(t_philosopher *philo);
void	ft_destroy_all(t_dining_table *table);

#endif
