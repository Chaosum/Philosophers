/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeannot <rjeannot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 14:23:46 by mservage          #+#    #+#             */
/*   Updated: 2021/04/29 14:44:53 by rjeannot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
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
