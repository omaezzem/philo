/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaezzem <omaezzem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 09:36:00 by omaezzem          #+#    #+#             */
/*   Updated: 2025/03/15 10:57:19 by omaezzem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	valid_number(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!(ft_isdigit(str[i])))
			return (0);
		i++;
	}
	return (1);
}

int	ft_to_int(char *str)
{
	unsigned long long int	nb;
	int 					i;

	i = 0;
	nb = 0;
	nb = atoi_ph(str, nb);
	if (nb > INT_MAX)
		return (-1);
	return ((int)nb);
}

void	validinput(int ac, char **av)
{
	int	i;
	int	nb;

	i = 1;
	while (i < ac)
	{
		nb = ft_to_int(av[i]);
		if (nb == -1)
			invalid_number();
		if (i == 1 && (!valid_number(av[i]) || nb > MAX_PHILO))
			invalid_n_philosopher();
		if ((i == 2 || i == 3) && !valid_number(av[i]))
			invalid_t_value();
		if (i == 4 && !valid_number(av[i]))
			invalid_number();
		if (i == 5 && (!valid_number(av[i]) || nb > MAX_MEAL))
			invalid_n_meals();
		i++;
	}
}