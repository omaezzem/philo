/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hyper.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaezzem <omaezzem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 08:56:53 by omaezzem          #+#    #+#             */
/*   Updated: 2025/04/09 15:13:05 by omaezzem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int philo_died(t_dining_table *table, int i)
{
    size_t current;
    
    pthread_mutex_lock(&table->time_lock);
    current = get_current_time();
    pthread_mutex_unlock(&table->time_lock);
    pthread_mutex_lock(&table->death_lock);
    if (((current - table->philosophers[i].last_meal_time) > (size_t)table->time_to_die)
        && table->die_flag == 0)
    {
        printf("%zu -> %d : %s", current - table->start_time, table->philosophers[i].id, MSG_DIED);
        table->die_flag = 1;
    }
    pthread_mutex_unlock(&table->death_lock);
    return (table->die_flag);
}

int philo_end(t_dining_table *table, int i)
{
    int all_ate;
    int j;

    if (!table || !table->philosophers || i < 0 || i >= table->philosopher_count)
        return (0);
    all_ate = 0;
    pthread_mutex_lock(&table->meal_lock);
    if (table->required_meals > 0 && \
        table->philosophers[i].meals_eaten >= table->required_meals)
    {
        all_ate = 1;
        j = -1;
        while (++j < table->philosopher_count && all_ate)
        {
            if (table->philosophers[j].meals_eaten < table->required_meals)
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

void hyper(t_dining_table *table)
{
    int i;

    i = 0;
    while (1)
    {
        if (philo_died(table, i) || philo_end(table, i))
            return;
        i++;
        if (i >= table->philosopher_count)
            i = 0;

        usleep(1000);
    }
    return ;
}

