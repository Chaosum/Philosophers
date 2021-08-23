/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_think.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matthieu <matthieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 12:41:38 by matthieu          #+#    #+#             */
/*   Updated: 2021/08/23 12:52:55 by matthieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	routine_think(t_philo *philo)
{
	gettimeofday(&philo->timestamp, NULL);
	if (!philo->prms->dead && !philo->prms->eat)
		printf("|%dms\t|%d\tis thinking\n",
			ft_get_time(philo->prms, philo->timestamp), philo->philo_nbr);
	pthread_mutex_unlock(&philo->prms->mutex_end);
	philo->current_state = 1;
}
