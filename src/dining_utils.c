/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dining_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaezzem <omaezzem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 21:32:26 by omaezzem          #+#    #+#             */
/*   Updated: 2025/05/17 13:13:18 by omaezzem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	safe_print(t_philosopher *philo, char *msg)
{
	pthread_mutex_lock(&philo->table->death_lock);
	if (!philo->table->die_flag)
	{
		printf("%zu   %d   %s",
			get_current_time() - philo->table->start_time,
			philo->id, msg);
	}
	pthread_mutex_unlock(&philo->table->death_lock);
}

void	increment_meal_count(t_philosopher *philo)
{
	pthread_mutex_lock(&philo->table->meal_lock);
	philo->meals_eaten++;
	pthread_mutex_unlock(&philo->table->meal_lock);
}

int	ft_exit_dining(t_philosopher *philo)
{
	pthread_mutex_lock(&philo->table->death_lock);
	if (philo->table->die_flag)
	{
		pthread_mutex_unlock(&philo->table->death_lock);
		return (1);
	}
	pthread_mutex_unlock(&philo->table->death_lock);
	return (0);
}
