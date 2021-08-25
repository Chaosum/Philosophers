/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mservage <mservage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 16:05:58 by matthieu          #+#    #+#             */
/*   Updated: 2021/08/25 17:34:43 by mservage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

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

void	ft_usleep(unsigned long int duration)
{
	struct timeval		current_time;
	unsigned long int	end;
	unsigned long int	current;

	gettimeofday(&current_time, NULL);
	current = current_time.tv_sec * 1000 + current_time.tv_usec / 1000;
	end = current + duration;
	while (current < end)
	{
		usleep(1000);
		gettimeofday(&current_time, NULL);
		current = current_time.tv_sec * 1000 + current_time.tv_usec / 1000;
	}
}
