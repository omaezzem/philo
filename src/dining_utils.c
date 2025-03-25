/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dining_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaezzem <omaezzem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 21:32:26 by omaezzem          #+#    #+#             */
/*   Updated: 2025/03/25 01:15:50 by omaezzem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void safe_print(t_philosopher *philo, char *msg)
{
    if (!philo || !philo->table || !msg)
        return;

    pthread_mutex_lock(&philo->table->print_lock);
    if (!philo->table->die_flag)
    {
        printf("%zu %d %s\n", get_current_time() - philo->table->start_time,
               philo->id, msg);
    }
    pthread_mutex_unlock(&philo->table->print_lock);
}

void update_last_meal_time(t_philosopher *philo)
{
    pthread_mutex_lock(&philo->table->time_lock);
    philo->last_meal_time = get_current_time();
    pthread_mutex_unlock(&philo->table->time_lock);
}

void increment_meal_count(t_philosopher *philo)
{
        pthread_mutex_lock(&philo->table->meal_lock);
        philo->meals_eaten++;
        pthread_mutex_unlock(&philo->table->meal_lock);
}

int ft_exit_dining(t_dining_table *table)
{
    int should_exit;

    if (!table)
        return 0;
    pthread_mutex_lock(&table->death_lock);
    should_exit = table->die_flag;
    pthread_mutex_unlock(&table->death_lock);
    return (!should_exit);
}
