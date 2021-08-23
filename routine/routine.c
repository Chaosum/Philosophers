/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matthieu <matthieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 23:41:27 by matthieu          #+#    #+#             */
/*   Updated: 2021/08/23 12:42:03 by matthieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	*ft_routine(void *args)
{
	t_philo	*philo;

	philo = args;
	pthread_detach(philo->thread);
	routine_think(philo);
	if (philo->philo_nbr % 2)
		usleep(2000);
	while (1)
	{
		pthread_mutex_lock(&philo->prms->mutex_end);
		if (philo->prms->dead == 0 && philo->current_state == 1
			&& philo->prms->eat == 0)
			routine_eat(philo);
		pthread_mutex_lock(&philo->prms->mutex_end);
		if (philo->prms->dead == 0 && philo->current_state == 2
			&& philo->prms->eat == 0)
			routine_sleep(philo);
		pthread_mutex_lock(&philo->prms->mutex_end);
		if (philo->prms->dead == 0 && philo->current_state == 3
			&& philo->prms->eat == 0)
			routine_think(philo);
		else
			break ;
	}
	return (NULL);
}

int	check_if_dead(t_philo_prms *prms, int i, struct timeval current_time)
{
	int	sec;
	int	usec;
	int	time;

	sec = current_time.tv_sec - prms->philo[i]->last_time_eat.tv_sec;
	usec = current_time.tv_usec - prms->philo[i]->last_time_eat.tv_usec;
	time = (sec * 1000) + (usec / 1000);
	if (prms->philo[i]->last_time_eat.tv_sec == 0)
		return (0);
	pthread_mutex_lock(&prms->mutex_end);
	if (time > prms->time_to_die && prms->philo[i]->fork != 2)
	{
		prms->dead = 1;
		pthread_mutex_unlock(&prms->mutex_end);
		printf("|%dms\t|%d\tdied\n",
			ft_get_time(prms, current_time), i + 1);
		return (1);
	}
	pthread_mutex_unlock(&prms->mutex_end);
	return (0);
}

int	check_if_fed(t_philo_prms *prms)
{
	int	nb_philo_fed;
	int	j;

	nb_philo_fed = 0;
	j = 0;
	if (prms->nbr_time_philo_must_eat)
	{
		while (prms->philo[j])
		{
			if (prms->philo[j]->nbr_time_eat >= prms->nbr_time_philo_must_eat)
				nb_philo_fed++;
			j++;
		}
		if (nb_philo_fed == prms->nbr_philo)
		{
			pthread_mutex_lock(&prms->mutex_end);
			prms->eat = 1;
			pthread_mutex_unlock(&prms->mutex_end);
			printf("Tout le monde il a bien manger\n");
			return (1);
		}
	}
	return (0);
}

void	*batch_routine(void	*args)
{
	t_philo_prms	*prms;
	int				i;
	struct timeval	current_time;

	prms = args;
	prms->eat = 0;
	usleep(100);
	while (prms->dead == 0 && prms->eat == 0)
	{
		i = 0;
		while (prms->philo[i])
		{
			gettimeofday(&current_time, NULL);
			if (check_if_dead(prms, i, current_time))
				break ;
			i++;
		}
		check_if_fed(prms);
		usleep(2000);
	}
	return (NULL);
}
