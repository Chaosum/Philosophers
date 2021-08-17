/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matthieu <matthieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 12:35:21 by matthieu          #+#    #+#             */
/*   Updated: 2021/08/17 14:21:06 by matthieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROUTINE_H
# define ROUTINE_H

# include "../philo.h"

/* routine_init.c */
int		init_philo_struct(t_philo_prms *prms, int i);
void	*ft_routine(void *args);
int		init_philo(t_philo_prms *prms);
long	ft_get_time(t_philo_prms *prms, struct timeval current_time);


/* routine_eat.c */
void	routine_eat(t_philo *philo);
void	philo_grab_fork(t_philo *philo);

/* routine_sleep.c */
void	routine_sleep(t_philo *philo);
void	ft_usleep(useconds_t time, t_philo *philo);

/* routine_think.c */
void	routine_think(t_philo *philo);

#endif