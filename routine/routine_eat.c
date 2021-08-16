/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_eat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mservage <mservage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 12:42:53 by matthieu          #+#    #+#             */
/*   Updated: 2021/08/16 21:06:48 by mservage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	routine_eat(t_philo *philo)
{
	if (philo->philo_nbr % 2)
	{
		pthread_mutex_lock(&philo->left_fork);
		philo_grab_fork(philo);
	}
	else
	{
		usleep(20);
		pthread_mutex_lock(&philo->right_fork);
		philo_grab_fork(philo);
	}
	if (philo->philo_nbr % 2)
	{
		pthread_mutex_lock(&philo->right_fork);
		philo_grab_fork(philo);
	}
	else
	{
		pthread_mutex_lock(&philo->left_fork);
		philo_grab_fork(philo);
	}
	gettimeofday(&philo->timestamp, NULL);
	philo->last_time_eat = philo->timestamp;
	printf("|%d%dms\t|%d\tis eating\n",
		(int)(philo->timestamp.tv_sec - philo->prms->timestamp.tv_sec),
		(int)((philo->timestamp.tv_usec) / 1000),
		philo->philo_nbr);
	philo->current_state = 2;
	usleep(philo->prms->time_to_eat * 1000);
	pthread_mutex_unlock(&philo->left_fork);
	pthread_mutex_unlock(&philo->right_fork);
}

void	philo_grab_fork(t_philo *philo)
{
	gettimeofday(&philo->timestamp, NULL);
	printf("|%d%dms\t|%d\thas taken a fork\n",
		(int)(philo->timestamp.tv_sec - philo->prms->timestamp.tv_sec),
		(int)((philo->timestamp.tv_usec) / 1000),
		philo->philo_nbr);
}
