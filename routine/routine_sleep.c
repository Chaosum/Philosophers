/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_sleep.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mservage <mservage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 12:42:21 by matthieu          #+#    #+#             */
/*   Updated: 2021/08/16 21:39:49 by mservage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	routine_sleep(t_philo *philo)
{
	gettimeofday(&philo->timestamp, NULL);
	printf("|%ld%dms\t|%d\tis sleeping\n",
		(philo->timestamp.tv_sec - philo->prms->timestamp.tv_sec),
		(philo->timestamp.tv_usec) / 1000,
		philo->philo_nbr);
	usleep(philo->prms->time_to_sleep * 1000);
	philo->current_state = 3;
}
