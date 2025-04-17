/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dining.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaezzem <omaezzem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 09:49:59 by omaezzem          #+#    #+#             */
/*   Updated: 2025/04/12 17:20:58 by omaezzem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	ft_think(t_philosopher *philo)
{
	pthread_mutex_lock(&philo->table->print_lock);
	safe_print(philo, MSG_THK);
	pthread_mutex_unlock(&philo->table->print_lock);
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

void	ft_sleep(t_philosopher *philo)
{
	safe_print(philo, MSG_SLP);
	ft_ph_sleep(philo->table->time_to_sleep, philo->table);
}

void	start_dining(t_philosopher *philo)
{
	if (philo->id % 2 == 0)
		ft_ph_sleep(philo->table->time_to_eat / 2, philo->table);
	while (1)
	{
		if (ft_exit_dining(philo))
			break ;
		ft_eat(philo);
		if (ft_exit_dining(philo))
			break ;
		ft_sleep(philo);
		if (ft_exit_dining(philo))
			break ;
		ft_think(philo);
	}
}
