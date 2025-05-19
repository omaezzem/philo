/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_destroy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaezzem <omaezzem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 17:30:49 by omaezzem          #+#    #+#             */
/*   Updated: 2025/04/19 10:37:04 by omaezzem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	ft_destroy_all(t_dining_table *table)
{
	int	i;

	if (!table)
		return ;
	if (table->forks)
	{
		i = -1;
		while (++i < table->philosopher_count)
		{
			pthread_mutex_destroy(&table->forks[i]);
		}
		free(table->forks);
	}
	if (table->philosophers)
	{
		free(table->philosophers);
	}
	pthread_mutex_destroy(&table->meal_lock);
	pthread_mutex_destroy(&table->death_lock);
	pthread_mutex_destroy(&table->print_lock);
	pthread_mutex_destroy(&table->time_lock);
}
