/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdegache <mdegache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 09:43:19 by mdegache          #+#    #+#             */
/*   Updated: 2025/06/16 15:13:03 by mdegache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	eat(t_philo *philos)
{
	int	time;
	
	pthread_mutex_lock(&philos->arg->eat);
	time = timestamp();
	print(philos, "is eating");
	usleep(philos->arg->time_e);
	pthread_mutex_unlock(&philos->fork);
	pthread_mutex_unlock(&philos->next->fork);
	pthread_mutex_unlock(&philos->arg->eat);
	usleep(philos->arg->time_s);
	print(philos, "is thinking");
}

void	print(t_philo *philos, char *str)
{
	int	time;
	
	pthread_mutex_lock(&philos->arg->print);
	time = timestamp() - philos->arg->time_start;
	printf("%d %d %s\n", time, philos->name, str);
	pthread_mutex_unlock(&philos->arg->print);
}

int    take_fork(t_philo *philos)
{
	pthread_mutex_lock(&philos->fork);
	print(philos, "has taken a fork");
	if (philos->arg->nb_philo == 1)
	{
		print(philos, "died");
		return (1);
	}
	pthread_mutex_lock(&philos->next->fork);
	print(philos, "has taken a fork");
	return (0);
}
