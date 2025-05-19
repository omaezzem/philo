/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaezzem <omaezzem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 09:03:13 by omaezzem          #+#    #+#             */
/*   Updated: 2025/05/09 14:46:58 by omaezzem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	ft_exit(char *err)
{
	printf("%s\n", err);
	return ;
}

size_t	get_current_time(void)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL))
		ft_exit("Gettimeofday faled");
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}
