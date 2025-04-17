/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaezzem <omaezzem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 07:39:36 by omaezzem          #+#    #+#             */
/*   Updated: 2025/03/22 09:34:54 by omaezzem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "../include/philo.h"

int main(int ac, char **av)
{
    t_dining_table table;
    int max_ph;

    if (ac < 5 || ac > 6)
        ft_putstr_fd(ERR_INV_ARG, 2);
    else
    {
        if (!validinput(ac, av)) 
            return 0;
        if (!init_dining_table(&table, av, ac))
            return 0;
        if (!yabesmellah(&table))
            return 0;
    }
}
