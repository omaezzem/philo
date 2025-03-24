/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaezzem <omaezzem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 09:36:38 by omaezzem          #+#    #+#             */
/*   Updated: 2025/03/23 22:40:22 by omaezzem         ###   ########.fr       */
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

typedef struct  s_dining_table t_dining_table;

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
    int philosopher_count;     // Number of philosophers participating in the simulation.
    int time_to_die;           // Time in milliseconds/seconds (or other units) before a philosopher dies if they haven't eaten.
    int time_to_eat;           // Time in milliseconds/seconds (or other units) it takes for a philosopher to eat.
    int time_to_sleep;         // Time in milliseconds/seconds (or other units) a philosopher will sleep after eating.
    int required_meals;        // Number of meals each philosopher must eat before the simulation ends.
    int die_flag;              // Flag indicating if the simulation has ended (e.g., 1 for over, 0 for running).
    size_t start_time;         // The time at which the simulation starts, typically stored as a timestamp.
    
    pthread_mutex_t meal_lock; // Mutex to protect access to philosopher's meal counts (to prevent race conditions).
    pthread_mutex_t time_lock; // Mutex to protect access to shared time data (e.g., start time).
    pthread_mutex_t print_lock; // Mutex to ensure safe printing, so multiple threads don't print at the same time.
    pthread_mutex_t death_lock; // Mutex for safely checking and updating the status of philosophers (alive or dead).
    
    pthread_mutex_t *forks;    // Pointer to an array of mutexes representing the forks. Each philosopher needs two forks to eat.
    t_philosopher *philosophers; // Pointer to an array of philosophers, each with its own state (e.g., meals eaten, thread, etc.).
} t_dining_table;


//                  src                     //

int     init_dining_table(t_dining_table *table, char **av, int ac);
int     bismillah(t_dining_table *table);
int     hyper(t_dining_table *table);

#endif
