/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matthieu <matthieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 16:06:49 by matthieu          #+#    #+#             */
/*   Updated: 2021/08/19 00:51:59 by matthieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "../philo.h"

/* utils.c */
int			ft_isdigit(int c);
int			ft_atoi(char *str);
void		*ft_calloc(size_t count, size_t size);
long int	get_timestamp(t_philo *philo);

/* error_checking.c */
void		args_reminder(void);
int			check_philo_arg_value(char **av);
void		ft_params_error(char *msg, int *error);
int			philo_error_and_init_params(int ac, t_philo_prms *prms, char **av);
int			philo_check_arg(int ac, char **av);
int			ft_error_display(char *msg, int ret, t_philo_prms *prms, int mutex);

/* memory_utils.c */
void		free_mutex(t_philo **philo);
void		ft_free_everything(t_philo_prms *prms);

#endif