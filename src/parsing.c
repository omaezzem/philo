/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaezzem <omaezzem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 09:36:00 by omaezzem          #+#    #+#             */
/*   Updated: 2025/05/09 09:57:40 by omaezzem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	valid_number(char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	if (str[i] == '\0')
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	ft_to_int(char *str)
{
	int	nb;

	nb = atoi_ph(str);
	if (nb == -1 || nb > INT_MAX)
		return (-1);
	return (nb);
}

int	check_zero_sexty(char **av, int i)
{
	if (ft_to_int(av[i]) == 0)
		return (0);
	if (ft_to_int(av[i]) < 60 && (i == 2 || i == 3 || i == 4))
		return (ft_putstr_fd("Error: argumants must be over 60\n", 2), 0);
	return (1);
}

int	ft_is_valid(char **av, int i)
{
	if (!valid_number(av[i]))
	{
		if (i == 1)
			return (ft_putstr_fd(ERR_INV_N_PHILO, 2), 0);
		else if (i == 2 || i == 3 || i == 4)
			return (ft_putstr_fd(ERR_INV_INPUT, 2), 0);
		else if (i == 5)
			return (ft_putstr_fd(ERR_INV_MEALS, 2), 0);
		return (0);
	}
	return (1);
}

int	validinput(int ac, char **av)
{
	int	i;
	int	nb;

	i = 0;
	while (++i < ac)
	{
		if (!ft_is_valid(av, i))
			return (0);
		if (!check_zero_sexty(av, i))
			return (0);
		nb = ft_to_int(av[i]);
		if (nb == -1)
			return (ft_putstr_fd(ERR_INV_NUM, 2), 0);
		if (i == 1 && nb > MAX_PHILO)
			return (ft_putstr_fd(ERR_INV_N_PHILO, 2), 0);
		if (i == 5 && nb > MAX_MEAL)
			return (ft_putstr_fd(ERR_INV_INPUT, 2), 0);
	}
	return (1);
}
