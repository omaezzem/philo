/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hyper.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaezzem <omaezzem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 08:56:53 by omaezzem          #+#    #+#             */
/*   Updated: 2025/03/23 22:37:02 by omaezzem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int philo_died(t_dining_table *table)
{
    size_t current;

    pthread_mutex_lock(&table->death_lock);
    pthread_mutex_lock(&table->time_lock);
    current = get_current_time();
    if ((current - table->philosophers->last_meal_time) > table->time_to_die
        && !table->die_flag)
    {
        table->die_flag = 1;
        printf("%zu -> %d : %s", current - table->start_time,
               table->philosophers->id, MSG_DIED);
        pthread_mutex_unlock(&table->death_lock);
        pthread_mutex_unlock(&table->time_lock);
        return (1);
    }
    pthread_mutex_unlock(&table->death_lock);
    pthread_mutex_unlock(&table->time_lock);
    return (0);
}

int philo_end(t_dining_table *table)
{
    int all_ate;
    int i;

    all_ate = 1;
    pthread_mutex_lock(&table->meal_lock);
    if (table->required_meals > 0)
    {
        i = -1;
        while (++i < table->philosopher_count)
        {
            if (table->philosophers[i].meals_eaten < table->required_meals)
            {
                all_ate = 0;
                break;
            }
        }
        if (all_ate)
        {
            pthread_mutex_lock(&table->death_lock);
            table->die_flag = 1;
            pthread_mutex_unlock(&table->death_lock);
        }
    }
    pthread_mutex_unlock(&table->meal_lock);
    return (all_ate);
}

int hyper(t_dining_table *table)
{
    while (1)
    {
        if (philo_died(table) || philo_end(table))
            return (1);
        usleep(1000);
    }
    return (0);
}