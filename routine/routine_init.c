/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mservage <mservage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 12:41:04 by matthieu          #+#    #+#             */
/*   Updated: 2021/08/20 20:28:34 by mservage         ###   ########.fr       */
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
	if (prms->nbr_philo == 1)
		gettimeofday(&prms->philo[i]->last_time_eat, NULL);
	if (pthread_mutex_init(&(temp->right_fork), NULL) == -1)
		return (ft_error_display("Error\nMemory issue\n", 1, prms, 1));
	return (0);
}

void	init_philo_fork(t_philo_prms *prms)
{
	int	i;

	i = 0;
	if (prms->nbr_philo == 1)
		return ;
	while (i < prms->nbr_philo)
	{
		if (i == 0)
			prms->philo[i]->left_fork
				= &prms->philo[prms->nbr_philo - 1]->right_fork;
		else
			prms->philo[i]->left_fork = &prms->philo[i - 1]->right_fork;
		i++;
	}
}

int	ft_get_time(t_philo_prms *prms, struct timeval current_time)
{
	long int	sec;
	long int	usec;
	int			time;

	sec = current_time.tv_sec - prms->timestamp.tv_sec;
	usec = current_time.tv_usec - prms->timestamp.tv_usec;
	time = (sec * 1000) + (usec / 1000);
	return (time);
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
	pthread_create(&prms->batch, NULL, batch_routine, prms);
	i = -1;
	while (++i < prms->nbr_philo)
		pthread_create(&prms->philo[i]->thread,
			NULL, ft_routine, prms->philo[i]);
	pthread_join(prms->batch, NULL);
	ft_free_everything(prms);
	return (0);
}
