/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matthieu <matthieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 14:39:44 by matthieu          #+#    #+#             */
/*   Updated: 2021/08/09 16:50:02 by matthieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_error_display(char *msg, int ret, void **to_be_free)
{
	int	i;

	i = -1;
	printf("%s", msg);
	if (to_be_free)
	{
		while (to_be_free[++i])
			free(to_be_free[i]);
		free(to_be_free[i]);
		free(to_be_free);
		to_be_free = NULL;
	}
	return (ret);
}

void	*ft_routine(t_philo_prms *prms)
{
	return ;
}

int	create_threads(t_philo_prms *prms)
{
	int				i;
	pthread_t		**thread;

	i = 0;
	thread = ft_calloc(prms->nbr_philo + 1, sizeof(pthread_t *));
	if (thread == NULL)
		return (ft_error_display("Error\nMemory issue\n", 1, NULL));
	while (i < prms->nbr_philo)
	{
		thread[i] = ft_calloc(1, sizeof(pthread_t));
		if (thread[i] == NULL)
			return (ft_error_display("Error\nMemory issue\n", 1, thread));
		if (pthread_create(thread[i], NULL, ft_routine, prms) == -1)
			return (1);/* destroy threads a faire et free */
		i++;
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_philo_prms	philo_params;

	if (philo_check_arg(ac, av))
		return (1);
	if (philo_init_params(&philo_params, av))
		return (1);
	if (create_threads(&philo_params))
		return (1);
}
