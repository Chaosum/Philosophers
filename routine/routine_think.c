/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_think.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matthieu <matthieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 12:41:38 by matthieu          #+#    #+#             */
/*   Updated: 2021/08/13 12:12:56 by matthieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	routine_think(t_philo *philo)
{
	gettimeofday(&philo->timestamp, NULL);
	printf("|%lds%ld\t|%d\tis thinking\n",
		(philo->timestamp.tv_sec - philo->prms->timestamp.tv_sec),
		(philo->timestamp.tv_usec) / 1000,
		philo->philo_nbr);
	philo->current_state = 1;
}
