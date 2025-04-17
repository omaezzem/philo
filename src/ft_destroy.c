/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_destroy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaezzem <omaezzem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 17:30:49 by omaezzem          #+#    #+#             */
/*   Updated: 2025/04/12 17:45:14 by omaezzem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	ft_destroy_all(t_dining_table *table)
{
	int	i;

	i = -1;
	while (++i < table->philosopher_count)
	{
		free(&table->forks[i]);
		pthread_mutex_destroy(&table->forks[i]);
	}
	i = -1;
	while (++i < table->philosopher_count)
	{
		free(&table->philosophers[i]);
	}
	pthread_mutex_destroy(&table->meal_lock);
	pthread_mutex_destroy(&table->death_lock);
	pthread_mutex_destroy(&table->print_lock);
	pthread_mutex_destroy(&table->time_lock);
}
