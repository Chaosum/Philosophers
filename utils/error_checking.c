/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_checking.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matthieu <matthieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 16:05:54 by matthieu          #+#    #+#             */
/*   Updated: 2021/08/19 01:00:53 by matthieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	args_reminder(void)
{
	static const char	*usage;

	usage = "|\t## ARGS SHOULD BE AS FOLLOWS ##\n"
		"|1st arg\t= number_of_philosophers\n"
		"|2nd arg\t= time_to_die - in  milliseconds\n"
		"|3rd arg\t= time_to_eat - in milliseconds\n"
		"|4th arg\t= time_to_sleep - in milliseconds\n"
		"|5th arg\t= number_of_times_each_philosopher_must_eat [optional]\n";
	printf("%s", usage);
}

int	check_philo_arg_value(char **av)
{
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

int	ft_error_display(char *msg, int ret, t_philo_prms *prms, int mutex)
{
	int	i;

	i = 0;
	if (msg)
		printf("%s", msg);
	if (prms->philo)
	{
		while (prms->philo[i])
			free(prms->philo[i++]);
		free(prms->philo[i++]);
		free(prms->philo);
	}
	if (mutex)
		free_mutex(prms->philo);
	return (ret);
}
