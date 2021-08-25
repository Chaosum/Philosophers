/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_sleep.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mservage <mservage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 12:42:21 by matthieu          #+#    #+#             */
/*   Updated: 2021/08/25 17:34:18 by mservage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	routine_sleep(t_philo *philo)
{
	pthread_mutex_unlock(&philo->prms->mutex_end);
	gettimeofday(&philo->timestamp, NULL);
	pthread_mutex_lock(&philo->prms->mutex_end);
	if (!philo->prms->dead && !philo->prms->eat)
	{
		pthread_mutex_unlock(&philo->prms->mutex_end);
		printf("|%dms\t|%d\tis sleeping\n",
			ft_get_time(philo->prms, philo->timestamp), philo->philo_nbr);
	}
	else
		pthread_mutex_unlock(&philo->prms->mutex_end);
	ft_usleep(philo->prms->time_to_sleep);
	philo->current_state = 3;
}
