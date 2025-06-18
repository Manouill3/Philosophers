/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdegache <mdegache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 09:43:19 by mdegache          #+#    #+#             */
/*   Updated: 2025/06/18 14:41:02 by mdegache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	check_death(t_philo *philo)
{
	int	time;

	time = timestamp();
	if (time - philo->time_leat >= philo->arg->time_d)
	{
		print(philo, "died");
		pthread_mutex_lock(&philo->arg->die);
		philo->arg->is_dead = 1;
		pthread_mutex_unlock(&philo->arg->die);
		return (1);
	}
	return (0);
}

int	eat(t_philo *philos)
{
	int	time;
	
	pthread_mutex_lock(&philos->arg->eat);
	time = timestamp();
	print(philos, "is eating");
	philos->count_dish += 1;
	philos->time_leat = timestamp();
	if (philos->arg->nb_dish == philos->count_dish || philos->arg->is_dead)
	{
		pthread_mutex_unlock(&philos->arg->eat);
		pthread_mutex_unlock(&philos->next->fork);
		pthread_mutex_unlock(&philos->fork);
		return (1);
	}
	ft_usleep(philos->arg->time_e);
	pthread_mutex_unlock(&philos->arg->eat);
	pthread_mutex_unlock(&philos->next->fork);
	pthread_mutex_unlock(&philos->fork);
	if (philos->arg->nb_dish == philos->count_dish || philos->arg->is_dead) 
		return (1);
	print(philos, "is sleeping");
	ft_usleep(philos->arg->time_s);
	print(philos, "is thinking");
	return (0);
}

void	print(t_philo *philos, char *str)
{
	int	time;
	
	pthread_mutex_lock(&philos->arg->die);
	if (!philos->arg->is_dead)
	{
		pthread_mutex_lock(&philos->arg->print);
		time = timestamp() - philos->arg->time_start;
		printf("%d %d %s\n", time, philos->name, str);
		pthread_mutex_unlock(&philos->arg->print);
	}
	pthread_mutex_unlock(&philos->arg->die);
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
