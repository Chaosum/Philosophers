/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_sleep.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mservage <mservage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 12:42:21 by matthieu          #+#    #+#             */
/*   Updated: 2021/08/20 21:23:43 by mservage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	routine_sleep(t_philo *philo)
{
	gettimeofday(&philo->timestamp, NULL);
	if (!philo->prms->dead && !philo->prms->eat)
		printf("|%dms\t|%d\tis sleeping\n",
			ft_get_time(philo->prms, philo->timestamp), philo->philo_nbr);
	pthread_mutex_unlock(&philo->prms->mutex_end);
	usleep(philo->prms->time_to_sleep * 1000);
	philo->current_state = 3;
}
