/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matthieu <matthieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 12:35:21 by matthieu          #+#    #+#             */
/*   Updated: 2021/08/19 01:09:54 by matthieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROUTINE_H
# define ROUTINE_H

# include "../philo.h"

/* routine_init.c */
int		init_philo_struct(t_philo_prms *prms, int i);
int		init_philo(t_philo_prms *prms);
int		ft_get_time(t_philo_prms *prms, struct timeval current_time);
void	init_philo_fork(t_philo_prms *prms);

/* routine_eat.c */
void	philo_grab_fork(t_philo *philo);
void	ft_lock_fork(t_philo *philo);
void	routine_eat(t_philo *philo);

/* routine_sleep.c */
void	routine_sleep(t_philo *philo);

/* routine_think.c */
void	routine_think(t_philo *philo);

/* routine.c */
void	*ft_routine(void *args);
int		check_if_dead(t_philo_prms *prms, int i, struct timeval current_time);
int		check_if_fed(t_philo_prms *prms);
void	*batch_routine(void	*args);

#endif