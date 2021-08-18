/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matthieu <matthieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 12:37:43 by matthieu          #+#    #+#             */
/*   Updated: 2021/08/19 00:52:12 by matthieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	free_mutex(t_philo **philo)
{
	t_philo	**temp;
	int		i;

	i = 0;
	temp = philo;
	while (temp[i])
	{
		pthread_mutex_destroy(&temp[i]->right_fork);
		i++;
	}
}

void	ft_free_everything(t_philo_prms *prms)
{
	int	i;

	i = 0;
	usleep(100);
	free_mutex(prms->philo);
	while (prms->philo[i])
	{
		free(prms->philo[i]);
		i++;
	}
	free(prms->philo[i]);
	free(prms->philo);
	return ;
}
