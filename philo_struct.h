/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_struct.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mservage <mservage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 15:20:29 by matthieu          #+#    #+#             */
/*   Updated: 2021/08/20 19:56:53 by mservage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_STRUCT_H
# define PHILO_STRUCT_H

typedef struct s_philo_prms	t_philo_prms;
typedef struct s_philo		t_philo;

typedef struct s_philo
{
	pthread_t			thread;
	int					philo_nbr;
	struct timeval		last_time_eat;
	int					nbr_time_eat;
	int					current_state;
	pthread_mutex_t		*left_fork;
	pthread_mutex_t		right_fork;
	int					fork;
	struct timeval		timestamp;
	t_philo_prms		*prms;
}		t_philo;

typedef struct s_philo_prms
{
	pthread_t			batch;
	pthread_mutex_t		mutex_end;
	int					nbr_philo;
	long int			time_to_die;
	long int			time_to_eat;
	long int			time_to_sleep;
	int					nbr_time_philo_must_eat;
	int					nb_forks;
	int					dead;
	int					eat;
	struct timeval		timestamp;
	t_philo				**philo;
}		t_philo_prms;

#endif
