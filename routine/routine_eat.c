/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_eat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mservage <mservage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 12:42:53 by matthieu          #+#    #+#             */
/*   Updated: 2021/08/25 19:00:05 by mservage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	philo_grab_fork(t_philo *philo)
{
	pthread_mutex_lock(&philo->prms->mutex_end);
	if (!philo->prms->dead && !philo->prms->eat)
	{	
		gettimeofday(&philo->timestamp, NULL);
		printf("|%dms\t|%d\thas taken a fork\n",
			ft_get_time(philo->prms, philo->timestamp), philo->philo_nbr);
	}
	pthread_mutex_unlock(&philo->prms->mutex_end);
	philo->fork++;
}

void	ft_lock_fork(t_philo *philo)
{
	if (philo->philo_nbr % 2)
	{
		pthread_mutex_lock(philo->left_fork);
		philo_grab_fork(philo);
	}
	else
	{
		usleep(10);
		pthread_mutex_lock(philo->left_fork);
		philo_grab_fork(philo);
	}
	if (philo->philo_nbr % 2)
	{
		pthread_mutex_lock(&philo->right_fork);
		philo_grab_fork(philo);
	}
	else
	{
		usleep(10);
		pthread_mutex_lock(&philo->right_fork);
		philo_grab_fork(philo);
	}
}

void	routine_eat(t_philo *philo)
{
	pthread_mutex_unlock(&philo->prms->mutex_end);
	if (philo->prms->nbr_philo == 1)
		return ;
	ft_lock_fork(philo);
	pthread_mutex_lock(&philo->prms->mutex_end);
	if (!philo->prms->dead && !philo->prms->eat)
	{
		gettimeofday(&philo->last_time_eat, NULL);
		if (philo->prms->nbr_time_philo_must_eat)
			philo->nbr_time_eat++;
		printf("|%dms\t|%d\tis eating\n",
			ft_get_time(philo->prms, philo->last_time_eat), philo->philo_nbr);
	}
	pthread_mutex_unlock(&philo->prms->mutex_end);
	philo->fork = 0;
	ft_usleep(philo->prms->time_to_eat);
	philo->current_state = 2;
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(&philo->right_fork);
}
