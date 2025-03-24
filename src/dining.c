/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dining.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaezzem <omaezzem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 09:49:59 by omaezzem          #+#    #+#             */
/*   Updated: 2025/03/24 03:46:28 by omaezzem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void     single_ph(t_dining_table *table)
{
    size_t  start_time = get_current_time();
    pthread_mutex_lock(&table->forks[0]);
    printf("%zu  -> %d : %s", get_current_time() - start_time,
            table->philosopher_count, MSG_FORK);
    usleep(table->time_to_die * 1000);
    printf("%zu  -> %d : %s", get_current_time() - start_time,
            table->philosopher_count, MSG_DIED);
    pthread_mutex_unlock(&table->forks[0]);
}

void    ft_eat(t_philosopher *philo)
{
        pthread_mutex_lock(philo->left_fork);
        pthread_mutex_lock(&philo->table->print_lock);
        print_ph(philo,MSG_FORK);
        pthread_mutex_lock(philo->right_fork);
        pthread_mutex_lock(philo->table.)
        
        
        
}

void    start_dining(t_philosopher *philo, t_dining_table *table)
{
        if ((philo->id % 2 == 0) || philo->id == table->philosopher_count)
                ft_ph_sleep(table->time_to_eat / 2, philo->table);
        while (1)
        {
                if (table->die_flag)
                        return ;
                pthread_mutex_lock(&table->death_lock);
                if (&table->death_lock)
                        return ;
                pthread_mutex_unlock(&table->death_lock);
                ft_eat
        }
                
}
int     bismillah(t_dining_table *table)
{
        pthread_t       hypervsr;
        int             i;

        i = 0;
        if (table->philosopher_count == 1)
                single_ph(table);
        if (pthread_create(&hypervsr, NULL, (void *)hyper, NULL) != 0)
                return 0;
        if (pthread_join(hypervsr, NULL) != 0)
                return 0;
        while (i < table->philosopher_count)
        {
                if (pthread_create(&table->philosophers[i], NULL, (void *)start_dining, NULL) != 0)
                        return 0;
                i++;
        }
        i = 0;
        while (i < table->philosopher_count)
        {
                if ((pthread_join(table->philosophers[i].thread, NULL)) != 0)
                        return 0;
                i++;
        }
        return 1; 
}

