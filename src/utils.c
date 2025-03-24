/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaezzem <omaezzem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 03:12:00 by omaezzem          #+#    #+#             */
/*   Updated: 2025/03/24 03:44:17 by omaezzem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int ft_ph_sleep(size_t time, t_dining_table*table)
{
    pthread_mutex_lock(&table->death_lock);
    if (table->die_flag)
    {
        pthread_mutex_unlock(&table->death_lock);
        return (0);
    }
    pthread_mutex_unlock(&table->death_lock);

    usleep(time);
    return (0);
}

void	print_ph(t_philosopher *philo, char *msg)
{
	pthread_mutex_lock(&philo->table->death_lock);
	if (!philo->table->die_flag)
		printf("%zu %d %s\n", get_time() - philo->table->start_time, \
		philo->id, msg);
	pthread_mutex_unlock(&philo->table->death_lock);
}
