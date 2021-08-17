/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_eat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matthieu <matthieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 12:42:53 by matthieu          #+#    #+#             */
/*   Updated: 2021/08/17 14:23:10 by matthieu         ###   ########.fr       */
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
	printf("|%ldms\t|%d\tis eating\n",
		ft_get_time(philo->prms, philo->timestamp), philo->philo_nbr);
	usleep(philo->prms->time_to_eat * 1000);
	philo->current_state = 2;
	if (philo->prms->nbr_time_philo_must_eat)
		philo->nbr_time_eat++;
	pthread_mutex_unlock(&philo->left_fork);
	pthread_mutex_unlock(&philo->right_fork);
}

void	philo_grab_fork(t_philo *philo)
{
	gettimeofday(&philo->timestamp, NULL);
	printf("|%ldms\t|%d\thas taken a fork\n",
		ft_get_time(philo->prms, philo->timestamp), philo->philo_nbr);
}
