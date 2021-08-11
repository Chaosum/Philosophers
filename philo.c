/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matthieu <matthieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 14:39:44 by matthieu          #+#    #+#             */
/*   Updated: 2021/08/11 16:26:12 by matthieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_mutex(t_philo **philo)
{
	t_philo	**temp;
	int		i;

	i = 0;
	temp = philo;
	while (temp[i])
	{
		pthread_mutex_destroy(&temp[i]->mutex);
		i++;
	}
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

void	*ft_routine(void *args)
{
	t_philo	*philo;

	philo = args;
	printf("philo numero %d cree\n", philo->philo_nbr);
	return (NULL);
}

int	init_philo_struct(t_philo_prms *prms, int i)
{
	t_philo	*temp;

	temp->philo_nbr = i + 1;
	temp->prms = prms;
	temp->fork_state = 1;
	temp->current_state = 1;
	if (pthread_mutex_init(&(temp->mutex), NULL) == -1)
		return (ft_error_display("Error\nMemory issue\n", 1, prms, 1));
	temp = prms->philo[i];
	return (0);
}

int	init_philo(t_philo_prms *prms)
{
	int	i;

	i = 0;
	prms->philo = ft_calloc(prms->nbr_philo + 1, sizeof(t_philo *));
	if (prms->philo == NULL)
		return (ft_error_display("Error\nMemory issue\n", 1, prms, 0));
	while (i < prms->nbr_philo)
	{
		prms->philo[i] = ft_calloc(1, sizeof(t_philo));
		if (prms->philo == NULL)
			return (ft_error_display("Error\nMemory issue\n", 1, prms, 0));
		if (init_philo_struct(prms, i))
			return (1);
		pthread_create(&prms->philo[i]->thread,
			NULL, ft_routine, prms->philo[i]);
		i++;
		usleep(10000);
	}
	return (0);
}

int	create_threads(t_philo_prms *prms)
{
	init_philo(prms);
	return (0);
}

int	main(int ac, char **av)
{
	t_philo_prms	philo_params;

	if (philo_check_arg(ac, av))
		return (1);
	if (philo_error_and_init_params(ac, &philo_params, av))
		return (1);
	if (create_threads(&philo_params))
		return (1);
}
