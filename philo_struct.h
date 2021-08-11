/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_struct.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matthieu <matthieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 15:20:29 by matthieu          #+#    #+#             */
/*   Updated: 2021/08/11 16:18:40 by matthieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_STRUCT_H
# define PHILO_STRUCT_H

typedef struct s_philo_prms	t_philo_prms;
typedef struct s_philo	t_philo;

typedef struct s_philo
{
	pthread_t		thread;
	int				philo_nbr;
	long			last_time_eat;
	long			last_time_sleep;
	int				nbr_time_eat;
	int				current_state;
	int				fork_state;
	pthread_mutex_t	mutex;
	t_philo_prms	*prms;
}		t_philo;

typedef struct s_philo_prms
{
	int				nbr_philo;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	int				nbr_time_philo_must_eat;
	int				nb_forks;
	t_philo			**philo;
}		t_philo_prms;

#endif
