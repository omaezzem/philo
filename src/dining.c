/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dining.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaezzem <omaezzem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 09:49:59 by omaezzem          #+#    #+#             */
/*   Updated: 2025/05/18 16:04:31 by omaezzem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	ft_think(t_philosopher *philo)
{
	pthread_mutex_lock(&philo->table->print_lock);
	safe_print(philo, MSG_THK);
	pthread_mutex_unlock(&philo->table->print_lock);
}

void	ft_sleep(t_philosopher *philo)
{
	safe_print(philo, MSG_SLP);
	ft_ph_sleep(philo->table->time_to_sleep, philo->table);
}

int	checkeat(t_philosopher *philo)
{
	pthread_mutex_lock(&philo->table->meal_lock);
	if (philo->meals_eaten == philo->table->required_meals)
		return (pthread_mutex_unlock(&philo->table->meal_lock), 1);
	pthread_mutex_unlock(&philo->table->meal_lock);
	return (0);
}

void	ft_eat(t_philosopher *philo)
{
	pthread_mutex_lock(philo->left_fork);
	pthread_mutex_lock(&philo->table->print_lock);
	safe_print(philo, MSG_FORK);
	pthread_mutex_unlock(&philo->table->print_lock);
	pthread_mutex_lock(philo->right_fork);
	pthread_mutex_lock(&philo->table->print_lock);
	safe_print(philo, MSG_FORK);
	pthread_mutex_unlock(&philo->table->print_lock);
	pthread_mutex_lock(&philo->table->print_lock);
	safe_print(philo, MSG_EAT);
	pthread_mutex_unlock(&philo->table->print_lock);
	pthread_mutex_lock(&philo->table->time_lock);
	philo->last_meal_time = get_current_time();
	pthread_mutex_unlock(&philo->table->time_lock);
	ft_ph_sleep(philo->table->time_to_eat, philo->table);
	increment_meal_count(philo);
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
}
