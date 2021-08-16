/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mservage <mservage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 14:39:44 by matthieu          #+#    #+#             */
/*   Updated: 2021/08/16 21:49:06 by mservage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philo_error_and_init_params(int ac, t_philo_prms *prms, char **av)
{
	int	error;

	error = 0;
	prms->nbr_philo = ft_atoi(av[1]);
	if (prms->nbr_philo == -1)
		ft_params_error("Error\nWrong philosophers number\n", &error);
	prms->time_to_die = ft_atoi(av[2]);
	if (prms->time_to_die == -1)
		ft_params_error("Error\nWrong time_to_die value\n", &error);
	prms->time_to_eat = ft_atoi(av[3]);
	if (prms->time_to_eat == -1)
		ft_params_error("Error\nWrong time_to_eat value\n", &error);
	prms->time_to_sleep = ft_atoi(av[4]);
	if (prms->time_to_sleep == -1)
		ft_params_error("Error\nWrong time_to_sleep value\n", &error);
	if (ac == 5)
		prms->nbr_time_philo_must_eat = 0;
	else
		prms->nbr_time_philo_must_eat = ft_atoi(av[5]);
	if (prms->nbr_time_philo_must_eat == -1)
		ft_params_error("Error\nWrong time philo must eat value\n", &error);
	prms->nb_forks = prms->nbr_philo;
	prms->philo = NULL;
	if (error)
		args_reminder();
	return (error);
}

int	main(int ac, char **av)
{
	t_philo_prms	philo_params;

	if (philo_check_arg(ac, av))
		return (1);
	if (philo_error_and_init_params(ac, &philo_params, av))
		return (1);
	if (init_philo(&philo_params))
		return (1);
	while (1);
}
