/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mservage <mservage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 12:41:04 by matthieu          #+#    #+#             */
/*   Updated: 2021/08/16 21:46:40 by mservage         ###   ########.fr       */
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
	int		dead;

	dead = 0;
	philo = args;
	routine_think(philo);
	while (philo->current_state)
	{
		if (!dead && philo->current_state == 1)
			routine_eat(philo);
		else if (!dead && philo->current_state == 2)
			routine_sleep(philo);
		else if (!dead && philo->current_state == 3)
			routine_think(philo);
	}
	printf("philo %d died\n", philo->philo_nbr);
	exit(0);
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

int	check_if_dead(t_philo_prms *prms, int i, struct timeval current_time)
{
	long int	sec;
	long int	usec;

	sec = current_time.tv_sec - prms->philo[i]->last_time_eat.tv_sec;
	usec = current_time.tv_usec - prms->philo[i]->last_time_eat.tv_usec;
	if (prms->philo[i]->last_time_eat.tv_sec == 0
		&& prms->philo[i]->last_time_eat.tv_usec == 0)
		return (0);
	if ((sec > prms->time_to_die / 1000)
		|| ((sec == prms->time_to_die / 1000)
			&& usec > ((prms->time_to_die * 1000) % 1000000)))
	{
		prms->philo[i]->current_state = 0;
		return (1);
	}
	return (0);
}

void	*batch_routine(void	*args)
{
	t_philo_prms	*prms;
	int				i;
	struct timeval	current_time;

	prms = args;
	while (1)
	{
		i = 0;
		gettimeofday(&current_time, NULL);
		while (prms->philo[i])
		{
			if (check_if_dead(prms, i, current_time))
				return (NULL);
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
	gettimeofday(&prms->timestamp, NULL);
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
	while (++i < prms->nbr_philo)
		pthread_create(&prms->philo[i]->thread,
			NULL, ft_routine, prms->philo[i]);
	batch_routine(prms);
	return (0);
}
