/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bismillah.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaezzem <omaezzem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 16:24:09 by omaezzem          #+#    #+#             */
/*   Updated: 2025/04/12 17:20:41 by omaezzem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	single_ph(t_dining_table *table)
{
	size_t	start_time;

	if (!table || !table->forks || !table->philosophers)
		return ;
	start_time = get_current_time();
	pthread_mutex_lock(&table->forks[0]);
	pthread_mutex_lock(&table->print_lock);
	printf("%zu -> %d : %s", get_current_time() - start_time,
		table->philosophers[0].id, MSG_FORK);
	pthread_mutex_unlock(&table->print_lock);
	usleep(table->time_to_die * 1000);
	pthread_mutex_lock(&table->print_lock);
	printf("%zu -> %d : %s", get_current_time() - start_time,
		table->philosophers[0].id, MSG_DIED);
	pthread_mutex_unlock(&table->print_lock);
	pthread_mutex_unlock(&table->forks[0]);
}

int	single_thread_ph(t_dining_table *table)
{
	pthread_t	single_thread;

	if (pthread_create(&single_thread, NULL, (void *)single_ph, table) != 0)
		return (0);
	if (pthread_join(single_thread, NULL) != 0)
		return (0);
	return (1);
}

int	bismillah(t_dining_table *table)
{
	pthread_t	hypervsr;
	int			i;

	i = -1;
	if (table->philosopher_count == 1)
		return (single_thread_ph(table), 0);
	if (pthread_create(&hypervsr, NULL, (void *)hyper, table) != 0)
		return (0);
	while (++i < table->philosopher_count)
	{
		if (pthread_create(&table->philosophers[i].thread, NULL,
				(void *)start_dining, &table->philosophers[i]) != 0)
			return (0);
	}
	i = -1;
	if (pthread_join(hypervsr, NULL) != 0)
		return (0);
	while (++i < table->philosopher_count)
	{
		if ((pthread_join(table->philosophers[i].thread, NULL)) != 0)
			return (0);
	}
	return (1);
}
