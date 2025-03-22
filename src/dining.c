/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dining.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaezzem <omaezzem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 09:49:59 by omaezzem          #+#    #+#             */
/*   Updated: 2025/03/21 10:01:16 by omaezzem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"


void     ft_single_philosopher(t_dining_table *table)
{
    size_t  start_time = get_current_time();
    pthread_mutex_lock(&table->forks[0]);
    printf("%zu  -> %d : %s ", get_current_time() - start_time,
            table->philosopher_count, MSG_FORK);
    usleep(table->time_to_die * 1000);
    printf("%zu  -> %d : %s ", get_current_time() - start_time,
            table->philosopher_count, MSG_DIED);
    pthread_mutex_unlock(&table->forks[0]);
}

