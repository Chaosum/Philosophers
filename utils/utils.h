/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matthieu <matthieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 16:06:49 by matthieu          #+#    #+#             */
/*   Updated: 2021/08/09 16:30:28 by matthieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "../philo.h"

/* utils.c */
int		ft_isdigit(int c);
int		ft_atoi(char *str);
void	*ft_calloc(size_t count, size_t size);

/* error_checking.c */
int		check_philo_arg_value(char **av);
void	ft_params_error(char *msg, int *error);
int		philo_init_params(t_philo_prms *prms, char **av);
int		philo_check_arg(int ac, char **av);

#endif