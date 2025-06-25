/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdegache <mdegache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 09:43:19 by mdegache          #+#    #+#             */
/*   Updated: 2025/06/25 13:27:38 by mdegache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	check_death(t_philo *philo)
{
	long long	time;

	time = timestamp() - philo->arg->time_start;
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

int	eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->arg->eat);
	print(philo, "is eating");
	philo->count_dish += 1;
	pthread_mutex_lock(&philo->arg->die);
	if (philo->arg->nb_dish == philo->count_dish || philo->arg->is_dead)
	{
		pthread_mutex_unlock(&philo->arg->die);
		pthread_mutex_unlock(&philo->arg->eat);
		pthread_mutex_unlock(&philo->next->fork);
		pthread_mutex_unlock(&philo->fork);
		return (1);
	}
	pthread_mutex_unlock(&philo->arg->die);
	pthread_mutex_unlock(&philo->arg->eat);
	philo->time_leat = timestamp() - philo->arg->time_start;
	if (ft_usleep(philo->arg->time_e, philo))
		return (1);
	pthread_mutex_unlock(&philo->next->fork);
	pthread_mutex_unlock(&philo->fork);
	pthread_mutex_lock(&philo->arg->die);
	if (philo->arg->nb_dish == philo->count_dish || philo->arg->is_dead)
	{
		pthread_mutex_unlock(&philo->arg->die);
		return (1);
	}
	pthread_mutex_unlock(&philo->arg->die);
	print(philo, "is sleeping");
	if (ft_usleep(philo->arg->time_s, philo))
		return (1);
	print(philo, "is thinking");
	return (0);
}

void	print(t_philo *philo, char *str)
{
	long long	time;

	pthread_mutex_lock(&philo->arg->die);
	printf("%d\n", philo->arg->is_dead);
	if (!philo->arg->is_dead)
	{
		pthread_mutex_lock(&philo->arg->print);
		time = timestamp() - philo->arg->time_start;
		printf("%lld %d %s\n", time, philo->name, str);
		pthread_mutex_unlock(&philo->arg->print);
	}
	pthread_mutex_unlock(&philo->arg->die);
}

int	take_fork(t_philo *philo)
{
	pthread_mutex_t	*first;
	pthread_mutex_t	*second;
	pthread_mutex_t	*tmp;

	first = &philo->fork;
	second = &philo->next->fork;
	if (first > second)
	{
		tmp = first;
		first = second;
		second = tmp;
	}
	if (philo->count_dish != 0)
		ft_wait(philo);
	pthread_mutex_lock(first);
	if ((timestamp() - philo->arg->time_start) - philo->time_leat >= philo->arg->time_d)
	{
		pthread_mutex_unlock(first);
		print(philo, "died");
		pthread_mutex_lock(&philo->arg->die);
		philo->arg->is_dead = 1;
		pthread_mutex_unlock(&philo->arg->die);
		return (1);
	}
	print(philo, "has taken a fork");
	if (philo->arg->nb_philo == 1)
	{
		ft_usleep(philo->arg->time_d, philo);
		print(philo, "died");
		pthread_mutex_unlock(&philo->fork);
		return (1);
	}
	pthread_mutex_lock(second);
	if ((timestamp() - philo->arg->time_start) - philo->time_leat >= philo->arg->time_d)
	{
		pthread_mutex_unlock(first);
		print(philo, "died");
		pthread_mutex_lock(&philo->arg->die);
		philo->arg->is_dead = 1;
		pthread_mutex_unlock(&philo->arg->die);
		return (1);
	}
	print(philo, "has taken a fork");
	return (0);
}
