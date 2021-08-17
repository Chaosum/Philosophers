/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_sleep.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matthieu <matthieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 12:42:21 by matthieu          #+#    #+#             */
/*   Updated: 2021/08/17 14:23:29 by matthieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	routine_sleep(t_philo *philo)
{
	gettimeofday(&philo->timestamp, NULL);
	printf("|%ldms\t|%d\tis sleeping\n",
		ft_get_time(philo->prms, philo->timestamp), philo->philo_nbr);
	usleep(philo->prms->time_to_sleep * 1000);
	philo->current_state = 3;
}
