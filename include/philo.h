/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaezzem <omaezzem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 09:36:38 by omaezzem          #+#    #+#             */
/*   Updated: 2025/03/21 09:56:39 by omaezzem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
#define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
#include <limits.h>
# include <sys/time.h>

#define MAX_PHILO 200
#define	MAX_MEAL 200

// error msg //
#define ERR_INV_N_PHILO "Error: Number of philosophers must be at least 1.\n"
#define ERR_INV_INPUT "Error: argumant must be positive integers.\n"
#define ERR_INV_MEALS "Error: number of meals must be positive integers.\n"
#define ERR_INV_ARG "Error: argumant must be a number\n"
#define ERR_INV_NUM "Error: argumant must be less or equal INT_MAX\n"
#define ERR_INV_ALOCATION "Error: failed allocation\n"
#define ERR_INIT "Error: failed initialized\n"

// msg philo //

#define MSG_FORK "has taken a fork\n"
#define MSG_DIED "died\n"

//                         utilis functions                         //

int		ft_isdigit(char c);
void	ft_putstr_fd(char *s, int fd);
int      atoi_ph(char *str);
int     ft_to_int(char *str);

//                         srcs functions                         //

int	validinput(int ac, char **av);
size_t	get_current_time(void);

//                         structers                             //

typedef struct s_philosopher {
    int id;
    pthread_t thread;
    size_t last_meal_time;
    int meals_eaten;
    pthread_mutex_t *left_fork;
    pthread_mutex_t *right_fork;
    t_dining_table *table;
} t_philosopher;

typedef struct s_dining_table {
    int philosopher_count;
    int time_to_die;
    int time_to_eat;
    int time_to_sleep;
    int required_meals;
    int simulation_over;
    size_t start_time;
    pthread_mutex_t meal_lock;
    pthread_mutex_t time_lock;
    pthread_mutex_t print_lock;
    pthread_mutex_t death_lock;
    pthread_mutex_t *forks;
    t_philosopher *philosophers;
} t_dining_table;


int     init_dining_table(t_dining_table *table, char **av, int ac);


#endif

