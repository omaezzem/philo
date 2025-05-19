/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaezzem <omaezzem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 07:39:36 by omaezzem          #+#    #+#             */
/*   Updated: 2025/05/19 19:42:51 by omaezzem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	hyper(t_dining_table *table)
{
	int	i;

	i = 0;
	while (1)
	{
		if (philo_died(table, i) || philo_end(table, i))
			return ;
		i++;
		if (i >= table->philosopher_count)
			i = 0;
		usleep(500);
	}
	return ;
}
void	f()
{
	system("leaks philo");
}
int	main(int ac, char **av)
{
	atexit(f);
	t_dining_table	table;

	if (ac < 5 || ac > 6)
	{
		ft_putstr_fd(ERR_INA, 2);
		ft_putstr_fd(ERR_USG, 2);
		return (1);
	}
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
			return (0);
		}
		if (!ft_start_dining(&table))
			ft_destroy_all(&table);
		ft_destroy_all(&table);
	}
}
