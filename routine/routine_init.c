/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matthieu <matthieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 12:41:04 by matthieu          #+#    #+#             */
/*   Updated: 2021/08/12 13:31:54 by matthieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	init_philo_struct(t_philo_prms *prms, int i)
{
	t_philo	*temp;

	temp->philo_nbr = i + 1;
	temp->prms = prms;
	temp->fork_state = 1;
	temp->current_state = 1;
	if (pthread_mutex_init(&(temp->right_fork), NULL) == -1)
		return (ft_error_display("Error\nMemory issue\n", 1, prms, 1));
	temp = prms->philo[i];
	return (0);
}

void	*ft_routine(void *args)
{
	t_philo	*philo;
	int		dead;

	dead = 0;
	philo = args;
	routine_think(philo);
	while (!dead)
	{
		if (!dead && philo->current_state == 1)
			routine_eat(philo);
		else if (!dead && philo->current_state == 2)
			routine_sleep(philo);
		else if (!dead && philo->current_state == 3)
			routine_think(philo);
	}
	printf("philo died\n");
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
	return (0);
}
