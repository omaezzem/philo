/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaezzem <omaezzem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 23:16:02 by omaezzem          #+#    #+#             */
/*   Updated: 2025/03/15 11:00:48 by omaezzem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"


int main(int ac, char **av)
{
    if (ac == 6)
    {
        validinput(ac, av);
    }
    else
        write (1, "EROOR\n", 6);
}