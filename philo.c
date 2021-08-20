/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mservage <mservage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 14:39:44 by matthieu          #+#    #+#             */
/*   Updated: 2021/08/20 20:01:31 by mservage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philo_error_params(t_philo_prms *prms)
{
	int	error;

	error = 0;
	if (prms->nbr_philo == -1)
		ft_params_error("Error\nWrong philosophers number\n", &error);
	if (prms->time_to_die == -1)
		ft_params_error("Error\nWrong time_to_die value\n", &error);
	if (prms->time_to_eat == -1)
		ft_params_error("Error\nWrong time_to_eat value\n", &error);
	if (prms->time_to_sleep == -1)
		ft_params_error("Error\nWrong time_to_sleep value\n", &error);
	if (prms->nbr_time_philo_must_eat == -1)
		ft_params_error("Error\nWrong time philo must eat value\n", &error);
	if (error)
		args_reminder();
	return (error);
}

int	philo_init_params(int ac, t_philo_prms *prms, char **av)
{
	prms->nbr_philo = ft_atoi(av[1]);
	prms->time_to_die = ft_atoi(av[2]);
	prms->time_to_eat = ft_atoi(av[3]);
	prms->time_to_sleep = ft_atoi(av[4]);
	if (ac == 5)
		prms->nbr_time_philo_must_eat = 0;
	else
		prms->nbr_time_philo_must_eat = ft_atoi(av[5]);
	prms->nb_forks = prms->nbr_philo;
	prms->philo = NULL;
	prms->dead = 0;
	pthread_mutex_init(&prms->mutex_end, NULL);
	return (philo_error_params(prms));
}

int	main(int ac, char **av)
{
	t_philo_prms	philo_params;

	if (philo_check_arg(ac, av))
		return (1);
	if (philo_init_params(ac, &philo_params, av))
		return (1);
	if (init_philo(&philo_params))
		return (1);
	return (0);
}
