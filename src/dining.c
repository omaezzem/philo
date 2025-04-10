/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dining.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaezzem <omaezzem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 09:49:59 by omaezzem          #+#    #+#             */
/*   Updated: 2025/04/10 16:12:22 by omaezzem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void single_ph(t_dining_table *table)
{
    size_t start_time;

    if (!table || !table->forks || !table->philosophers)
        return;
    start_time = get_current_time();
    pthread_mutex_lock(&table->forks[0]);
    printf("%zu -> %d : %s", get_current_time() - start_time,
           table->philosophers[0].id, MSG_FORK);
    usleep(table->time_to_die * 1000);
    printf("%zu -> %d : %s", get_current_time() - start_time,
           table->philosophers[0].id, MSG_DIED);
    pthread_mutex_unlock(&table->forks[0]);
}

void	ft_think(t_philosopher *philo)
{
	pthread_mutex_lock(&philo->table->print_lock);
	safe_print(philo, MSG_THK);
	pthread_mutex_unlock(&philo->table->print_lock);
}

void    ft_eat(t_philosopher *philo)
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
        update_last_meal_time(philo);
	ft_ph_sleep(philo->table->time_to_eat, philo->table);
        increment_meal_count(philo);
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
}

void    ft_sleep(t_philosopher *philo)
{
        pthread_mutex_lock(&philo->table->print_lock);
        safe_print(philo, MSG_SLP);
        pthread_mutex_unlock(&philo->table->print_lock);
        ft_ph_sleep(philo->table->time_to_sleep, philo->table);
}

void    start_dining(t_philosopher *philo)
{
        if (philo->id % 2 == 0)
                ft_ph_sleep(philo->table->time_to_eat / 2, philo->table);
        while (!ft_exit_dining(philo))
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
        return ;
}

int    single_thread_ph(t_dining_table *table)
{
        pthread_t       single_thread;

        if (pthread_create(&single_thread, NULL, (void *)single_ph, table) != 0)
                return (0);
        if (pthread_join(single_thread, NULL) != 0)
                return (0);
        return (1);
}

int     bismillah(t_dining_table *table)
{
        pthread_t       hypervsr;
        int             i;

        i = -1;
	if (table->philosopher_count == 1)
                return (single_thread_ph(table), 0);
        if (pthread_create(&hypervsr, NULL, (void *)hyper, table) != 0)
                return 0;
        while (++i < table->philosopher_count)
        {
                if (pthread_create(&table->philosophers[i].thread, NULL,
                        (void *)start_dining, &table->philosophers[i]) != 0)
                        return 0;
        }
        i = -1;
        if (pthread_join(hypervsr, NULL) != 0)
                return 0;
        while (++i < table->philosopher_count)
        {
                if ((pthread_join(table->philosophers[i].thread, NULL)) != 0)
                        return 0;
        }
        return 1;
}
