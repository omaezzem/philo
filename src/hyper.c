/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hyper.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaezzem <omaezzem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 08:56:53 by omaezzem          #+#    #+#             */
/*   Updated: 2025/05/17 13:31:43 by omaezzem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	all_philosophers_ate(t_dining_table *table)
{
	int	j;

	j = -1;
	while (++j < table->philosopher_count)
	{
		if (table->philosophers[j].meals_eaten < table->required_meals)
			return (0);
	}
	return (1);
}

int	philo_died(t_dining_table *table, int i)
{
	size_t	current;
	size_t	last_meal;

	pthread_mutex_lock(&table->time_lock);
	current = get_current_time();
	last_meal = table->philosophers[i].last_meal_time;
	pthread_mutex_unlock(&table->time_lock);
	pthread_mutex_lock(&table->death_lock);
	if (!table->die_flag && (current - last_meal)
		> (size_t)table->time_to_die)
	{
		printf("%zu    %d   %s\n",
			current - table->start_time, table->philosophers[i].id, MSG_DIED);
		table->die_flag = 1;
		pthread_mutex_unlock(&table->death_lock);
		return (1);
	}
	pthread_mutex_unlock(&table->death_lock);
	return (0);
}

int	philo_end(t_dining_table *table, int i)
{
	int	should_end;

	if (!table || !table->philosophers || i < 0
		|| i >= table->philosopher_count)
		return (0);
	should_end = 0;
	pthread_mutex_lock(&table->meal_lock);
	if (table->required_meals > 0
		&& table->philosophers[i].meals_eaten >= table->required_meals)
	{
		if (all_philosophers_ate(table))
		{
			pthread_mutex_lock(&table->death_lock);
			table->die_flag = 1;
			pthread_mutex_unlock(&table->death_lock);
			should_end = 1;
		}
	}
	pthread_mutex_unlock(&table->meal_lock);
	return (should_end);
}
