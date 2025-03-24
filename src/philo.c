/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaezzem <omaezzem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 07:40:16 by omaezzem          #+#    #+#             */
/*   Updated: 2025/03/23 22:38:04 by omaezzem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void ft_init_philosophers(t_dining_table *table, int i)
{
    while (i < table->philosopher_count)
    {
        table->philosophers[i].id = i + 1;
        table->philosophers[i].last_meal_time = table->start_time;
        table->philosophers[i].meals_eaten = 0;
        table->philosophers[i].table = table;
        table->philosophers[i].right_fork = &table->forks[i];
        table->philosophers[i].left_fork = &table->forks[(i + 1) % table->philosopher_count];
        i++;
    }
}

int ft_init_mutex_forks(t_dining_table *table, int i)
{
    while(table->philosopher_count > i)
    {
        if (pthread_mutex_init(&table->forks[i], NULL) != 0)
        {
            while (i > 0)
            {
                pthread_mutex_destroy(&table->forks[i]);
                i--;
            }
            free(table->forks);
        }
        i++;
    }
    return 1;
}

int ft_init_mutex_table(t_dining_table *table)
{
    if (pthread_mutex_init(&table->meal_lock, NULL) != 0)
        return 0;
    if (pthread_mutex_init(&table->time_lock, NULL) != 0)
        return 0;
    if (pthread_mutex_init(&table->print_lock, NULL) != 0) 
        return 0;
    if (pthread_mutex_init(&table->death_lock, NULL) != 0)
        return 0;
    return 1;
}

int     init_dining_table(t_dining_table *table, char **av, int ac)
{
    table->philosopher_count = ft_to_int(av[1]);
    table->time_to_die = ft_to_int(av[2]);
    table->time_to_eat = ft_to_int(av[3]);
    table->time_to_sleep = ft_to_int(av[4]);
    table->required_meals = -1;
    if (ac == 6)
        table->required_meals = ft_to_int(av[5]);
    table->die_flag = 0;
    table->start_time = get_current_time();
    if (!ft_init_mutex_table(table))
        return 0;
    table->forks = malloc(sizeof(pthread_mutex_t) * table->philosopher_count);
    if (!table->forks)
        return (ft_putstr_fd(ERR_INV_ALOCATION, 2), 0);
    if (!ft_init_mutex_forks(table, 0))
        return 0;
    table->philosophers = malloc(sizeof(t_philosopher) * table->philosopher_count);
    if (!table->philosophers)
        return (free(table->forks), ft_putstr_fd(ERR_INV_ALOCATION, 2), 0);
    ft_init_philosophers(table, 0);
    return 1;
}
