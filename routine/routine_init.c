/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matthieu <matthieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 12:41:04 by matthieu          #+#    #+#             */
/*   Updated: 2021/08/17 14:42:08 by matthieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	init_philo_struct(t_philo_prms *prms, int i)
{
	t_philo	*temp;

	temp = prms->philo[i];
	temp->philo_nbr = i + 1;
	temp->prms = prms;
	temp->current_state = 1;
	if (pthread_mutex_init(&(temp->right_fork), NULL) == -1)
		return (ft_error_display("Error\nMemory issue\n", 1, prms, 1));
	return (0);
}

void	*ft_routine(void *args)
{
	t_philo	*philo;

	philo = args;
	routine_think(philo);
	while (philo->current_state && philo->prms->dead == 0
		&& philo->prms->eat == 0)
	{
		if (philo->prms->dead == 0 && philo->current_state == 1
			&& philo->prms->eat == 0)
			routine_eat(philo);
		else if (philo->prms->dead == 0 && philo->current_state == 2
			&& philo->prms->eat == 0)
			routine_sleep(philo);
		else if (philo->prms->dead == 0 && philo->current_state == 3
			&& philo->prms->eat == 0)
			routine_think(philo);
	}
	return (NULL);
}

void	init_philo_fork(t_philo_prms *prms)
{
	int	i;

	i = 0;
	while (i < prms->nbr_philo)
	{
		if (i == 0)
			prms->philo[i]->left_fork
				= prms->philo[prms->nbr_philo - 1]->left_fork;
		else
			prms->philo[i]->left_fork = prms->philo[i - 1]->left_fork;
		i++;
	}
}

long	ft_get_time(t_philo_prms *prms, struct timeval current_time)
{
	long int	sec;
	long int	usec;
	long int	time;

	sec = current_time.tv_sec - prms->timestamp.tv_sec;
	usec = current_time.tv_usec - prms->timestamp.tv_usec;
	time = (sec * 1000) + (usec / 1000);
	return (time);
}

int	check_if_dead(t_philo_prms *prms, int i, struct timeval current_time)
{
	long int	sec;
	long int	usec;
	long int	time;

	sec = current_time.tv_sec - prms->philo[i]->last_time_eat.tv_sec;
	usec = current_time.tv_usec - prms->philo[i]->last_time_eat.tv_usec;
	time = (sec * 1000) + (usec / 1000);
	if (prms->philo[i]->last_time_eat.tv_sec == 0)
		return (0);
	if (time > prms->time_to_die)
	{
		printf("|%ldms\t|%d\tdied\n",
			ft_get_time(prms, current_time), i + 1);
		prms->philo[i]->current_state = 0;
		prms->dead = 1;
		return (1);
	}
	return (0);
}

int	check_if_fed(t_philo_prms *prms, int i)
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
			prms->eat = 1;
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
	prms->eat == 0;
	while (prms->dead == 0 && prms->eat == 0)
	{
		i = 0;
		gettimeofday(&current_time, NULL);
		while (prms->philo[i])
		{
			if (check_if_dead(prms, i, current_time))
				break ;
			if (check_if_fed(prms, i))
				break ;
			i++;
		}
	}
	return (NULL);
}

int	init_philo(t_philo_prms *prms)
{
	int	i;

	i = 0;
	prms->philo = ft_calloc(prms->nbr_philo + 1, sizeof(t_philo *));
	if (prms->philo == NULL)
		return (ft_error_display("Error\nMemory issue\n", 1, prms, 0));
	while (i < prms->nbr_philo)
	{
		prms->philo[i] = ft_calloc(1, sizeof(t_philo));
		if (prms->philo == NULL)
			return (ft_error_display("Error\nMemory issue\n", 1, prms, 0));
		if (init_philo_struct(prms, i))
			return (1);
		i++;
	}
	init_philo_fork(prms);
	i = -1;
	gettimeofday(&prms->timestamp, NULL);
	while (++i < prms->nbr_philo)
		pthread_create(&prms->philo[i]->thread,
			NULL, ft_routine, prms->philo[i]);
	batch_routine(prms);
	return (0);
}
