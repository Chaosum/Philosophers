/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_checking.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matthieu <matthieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 16:05:54 by matthieu          #+#    #+#             */
/*   Updated: 2021/08/11 16:20:21 by matthieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	args_reminder(void)
{
	printf("|\t## ARGS SHOULD BE AS FOLLOWS ##\n");
	printf("|1st arg\t= number_of_philosophers\n");
	printf("|2nd arg\t= time_to_die - in  miliseconds\n");
	printf("|3rd arg\t= time_to_eat - in miliseconds\n");
	printf("|4th arg\t= time_to_sleep - in miliseconds\n");
	printf("|5th arg\t= number_of_times_each_philosopher_must_eat(optional)\n");
}

int	check_philo_arg_value(char **av)
{
	char	*arg_check;
	int		i;
	int		j;
	int		error;

	i = 1;
	error = 0;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if (ft_isdigit(av[i][j]))
			{
				printf("Error\n Wrong arg number %d value : %s\n", i, av[i]);
				error = 1;
				break ;
			}
			j++;
		}
		i++;
	}
	if (error)
		args_reminder();
	return (error);
}

void	ft_params_error(char *msg, int *error)
{
	printf("%s", msg);
	*error = 1;
}

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
		prms->nbr_time_philo_must_eat = 1;
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

int	philo_check_arg(int ac, char **av)
{
	if (ac != 6 && ac != 5)
	{
		write(2, "Error\nWrong number of args\n", 28);
		args_reminder();
		return (1);
	}
	if (check_philo_arg_value(av))
		return (1);
	return (0);
}
