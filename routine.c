/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdegache <mdegache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 09:43:19 by mdegache          #+#    #+#             */
/*   Updated: 2025/06/13 09:10:29 by mdegache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	print(t_philo *philos, char *str)
{
	int	time;
	
	pthread_mutex_lock(&philos->arg->print);
	time = 
}

void    take_fork(t_philo *philos)
{
	if (philos->arg->nb_philo == 1)
	{
		print(philos, "died");
		return ;
	}
	pthread_mutex_lock(&philos->fork);
	print(philos, "has taken a fork\n");
	pthread_mutex_lock(&philos->prev->fork);
	print(philos, "has taken a fork\n");
}
