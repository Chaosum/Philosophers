/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_eat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matthieu <matthieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 12:42:53 by matthieu          #+#    #+#             */
/*   Updated: 2021/08/13 12:25:41 by matthieu         ###   ########.fr       */
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
	printf("|%lds%ld\t|%d\tis eating\n",
		(philo->timestamp.tv_sec - philo->prms->timestamp.tv_sec),
		(philo->timestamp.tv_usec) / 1000,
		philo->philo_nbr);
	usleep(philo->prms->time_to_eat);
	pthread_mutex_lock(&philo->left_fork);
	pthread_mutex_lock(&philo->right_fork);
	philo->current_state = 2;
}

void	philo_grab_fork(t_philo *philo)
{
	gettimeofday(&philo->timestamp, NULL);
	printf("|%lds%ld\t|%d\thas taken a fork\n",
		(philo->timestamp.tv_sec - philo->prms->timestamp.tv_sec),
		(philo->timestamp.tv_usec) / 1000,
		philo->philo_nbr);
}
