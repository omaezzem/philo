/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaezzem <omaezzem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 03:12:00 by omaezzem          #+#    #+#             */
/*   Updated: 2025/03/25 01:26:43 by omaezzem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int ft_ph_sleep(size_t time, t_dining_table *table)
{
    size_t slept = 0;
    while (slept < time)
    {
        if (ft_exit_dining(table))
            return 1;
        usleep(1000);
        slept += 1000;
    }
    return 0;
}

