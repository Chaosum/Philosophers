/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mservage <mservage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 14:40:07 by matthieu          #+#    #+#             */
/*   Updated: 2021/08/16 18:19:57 by mservage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include <string.h>

# include "philo_struct.h"
# include "./utils/utils.h"
# include "./routine/routine.h"

/* philo.c */
int	main(int ac, char **av);
int	philo_error_and_init_params(int ac, t_philo_prms *prms, char **av);

#endif