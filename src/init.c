/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaezzem <omaezzem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 07:40:16 by omaezzem          #+#    #+#             */
/*   Updated: 2025/05/17 12:54:20 by omaezzem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	init_mutex(pthread_mutex_t *mutex)
{
	return (pthread_mutex_init(mutex, NULL) == 0);
}

void	ft_init_philosophers(t_dining_table *table, int i)
{
	t_philosopher	*philo;

	while (i < table->philosopher_count)
	{
		philo = &table->philosophers[i];
		philo->id = i + 1;
		philo->last_meal_time = table->start_time;
		philo->meals_eaten = 0;
		philo->table = table;
		philo->right_fork = &table->forks[i];
		philo->left_fork = &table->forks[(i + 1)
			% table->philosopher_count];
		i++;
	}
}

int	ft_init_mutex_forks(t_dining_table *table, int i)
{
	while (table->philosopher_count > i)
	{
		if (pthread_mutex_init(&table->forks[i], NULL) != 0)
		{
			while (i > 0)
			{
				pthread_mutex_destroy(&table->forks[i]);
				i--;
			}
			free(table->forks);
		}
		i++;
	}
	return (1);
}

int	ft_init_mutex_table(t_dining_table *table)
{
	return (init_mutex(&table->meal_lock)
		&& init_mutex(&table->time_lock)
		&& init_mutex(&table->print_lock)
		&& init_mutex(&table->death_lock));
}

int	init_dining_table(t_dining_table *table, char **av, int ac)
{
	table->philosopher_count = ft_to_int(av[1]);
	table->time_to_die = ft_to_int(av[2]);
	table->time_to_eat = ft_to_int(av[3]);
	table->time_to_sleep = ft_to_int(av[4]);
	table->required_meals = 0;
	if (ac == 6)
		table->required_meals = ft_to_int(av[5]);
	table->die_flag = 0;
	table->start_time = get_current_time();
	if (!ft_init_mutex_table(table))
		return (0);
	table->forks = malloc(sizeof(pthread_mutex_t)
			* table->philosopher_count);
	if (!table->forks)
		return (ft_putstr_fd(ERR_INV_ALOCATION, 2), 0);
	if (!ft_init_mutex_forks(table, 0))
		return (0);
	table->philosophers = malloc(sizeof(t_philosopher)
			* table->philosopher_count);
	if (!table->philosophers)
		return (free(table->forks), ft_putstr_fd(ERR_INV_ALOCATION, 2), 0);
	ft_init_philosophers(table, 0);
	return (1);
}
