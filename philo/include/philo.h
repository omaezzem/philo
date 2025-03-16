/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaezzem <omaezzem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 09:36:38 by omaezzem          #+#    #+#             */
/*   Updated: 2025/03/15 10:56:44 by omaezzem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
#define PHILO_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_PHILO 200
#define	MAX_MEAL 200

//                         utilis functions                         //

int		ft_isdigit(char c);
void	ft_putstr_fd(char *s, int fd);
int		atoi_ph(char *str, int nb);

//                         error functions                         //

void	invalid_n_philosopher(void);
void	invalid_t_value(void);
void	invalid_n_meals(void);
void	invalid_arg(void);
void	invalid_number(void);

//                         srcs functions                         //

void	validinput(int ac, char **av);

#endif

