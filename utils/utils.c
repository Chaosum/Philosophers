/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matthieu <matthieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 16:05:58 by matthieu          #+#    #+#             */
/*   Updated: 2021/08/12 14:59:48 by matthieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

// long int	get_timestamp(t_philo *philo)
// {
// 	long int	time_sec;
// 	long int	time_usec;
// 	long int	time;

// 	time_sec = ((philo->timestamp.tv_sec - philo->prms->timestamp.tv_sec));
// 	time_usec = ((philo->timestamp.tv_usec - philo->prms->timestamp.tv_usec));
// 	time = time_sec * 1000 + time_usec / 1000;
// 	return (time);
// }

int	ft_isdigit(int c)
{
	if ((c >= '0') && (c <= '9'))
		return (0);
	return (1);
}

int	ft_atoi(char *str)
{
	int					i;
	unsigned long int	a;
	int					neg;

	i = 0;
	a = 0;
	neg = 1;
	while ((str[i] >= 9) && ((str[i] <= 13) || (str[i] == 32)))
		i++;
	if ((str[i] == '-' || str[i] == '+'))
	{
		if (str[i] == '-')
			neg = -neg;
		i++;
	}
	while (((str[i] >= '0') && (str[i] <= '9')) && (str[i]))
		a = a * 10 + (str[i++] - '0');
	if ((a > 2147483648) && (neg > 0))
		return (-1);
	else if ((a > 2147483648) && (neg < 0))
		return (0);
	return (a * neg);
}

void	*ft_calloc(size_t count, size_t size)
{
	size_t	i;
	void	*ptr;

	i = 0;
	ptr = malloc(size * count);
	if (ptr == NULL)
		return (NULL);
	while (i < (size * count))
	{
		((unsigned char *)ptr)[i] = 0;
		i++;
	}
	return (ptr);
}
