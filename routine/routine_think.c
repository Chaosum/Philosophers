/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_think.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mservage <mservage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 12:41:38 by matthieu          #+#    #+#             */
/*   Updated: 2021/08/16 21:07:34 by mservage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	routine_think(t_philo *philo)
{
	gettimeofday(&philo->timestamp, NULL);
	printf("|%d%dms\t|%d\tis thinking\n",
		(int)(philo->timestamp.tv_sec - philo->prms->timestamp.tv_sec),
		(int)((philo->timestamp.tv_usec) / 1000),
		philo->philo_nbr);
	philo->current_state = 1;
}
