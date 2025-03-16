/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errormsg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaezzem <omaezzem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 09:38:28 by omaezzem          #+#    #+#             */
/*   Updated: 2025/03/15 10:39:52 by omaezzem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	invalid_n_philosopher(void)
{
	ft_putstr_fd("Error: Number of philosophers must be at least 1.", 2);
	exit(1);
}

void	invalid_t_value(void)
{
	ft_putstr_fd("Error: Time values must be positive integers.", 2);
	exit(1);
}

void	invalid_n_meals(void)
{
	ft_putstr_fd("Error: Number of meals must be a positive integer.", 2);
	exit(1);
}

void	invalid_arg(void)
{
	ft_putstr_fd("Error: argumant must be a number", 2);
	exit(1);
}

void	invalid_number(void)
{
	ft_putstr_fd("Error: argumant must be less or equal INT_MAX", 2);
	exit(1);
}