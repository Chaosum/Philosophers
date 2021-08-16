/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_sleep.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matthieu <matthieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 12:42:21 by matthieu          #+#    #+#             */
/*   Updated: 2021/08/13 12:12:59 by matthieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	routine_sleep(t_philo *philo)
{
	gettimeofday(&philo->timestamp, NULL);
	printf("|%lds%ld\t|%d\tis sleeping\n",
		(philo->timestamp.tv_sec - philo->prms->timestamp.tv_sec),
		(philo->timestamp.tv_usec) / 1000,
		philo->philo_nbr);
	usleep(philo->prms->time_to_sleep);
	philo->current_state = 3;
}
