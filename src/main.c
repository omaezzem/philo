/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaezzem <omaezzem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 07:39:36 by omaezzem          #+#    #+#             */
/*   Updated: 2025/04/18 16:31:07 by omaezzem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	main(int ac, char **av)
{
	t_dining_table	table;

	if (ac < 5 || ac > 6)
		ft_putstr_fd(ERR_INV_ARG, 2);
	else
	{
		if (!validinput(ac, av))
			return (0);
		if (!init_dining_table(&table, av, ac))
			return (0);
		if (table.philosopher_count == 1)
		{
			single_thread_ph(&table);
			ft_destroy_all(&table);
			exit(1);
		}
		if (!ft_start_dining(&table))
			ft_destroy_all(&table);
		ft_destroy_all(&table);
	}
}
