/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_eat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matthieu <matthieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 12:42:53 by matthieu          #+#    #+#             */
/*   Updated: 2021/08/19 01:20:02 by matthieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	philo_grab_fork(t_philo *philo)
{
	gettimeofday(&philo->timestamp, NULL);
	if (!philo->prms->dead)
		printf("|%dms\t|%d\thas taken a fork\n",
			ft_get_time(philo->prms, philo->timestamp), philo->philo_nbr);
	philo->fork++;
}

void	ft_lock_fork(t_philo *philo)
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
		usleep(20);
		pthread_mutex_lock(&philo->left_fork);
		philo_grab_fork(philo);
	}
}

void	routine_eat(t_philo *philo)
{
	ft_lock_fork(philo);
	gettimeofday(&philo->last_time_eat, NULL);
	if (!philo->prms->dead)
		printf("|%dms\t|%d\tis eating\n",
			ft_get_time(philo->prms, philo->last_time_eat), philo->philo_nbr);
	usleep(philo->prms->time_to_eat * 1000);
	philo->fork = 0;
	philo->current_state = 2;
	if (philo->prms->nbr_time_philo_must_eat)
		philo->nbr_time_eat++;
	pthread_mutex_unlock(&philo->left_fork);
	pthread_mutex_unlock(&philo->right_fork);
}
