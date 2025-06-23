/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdegache <mdegache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 13:38:01 by mdegache          #+#    #+#             */
/*   Updated: 2025/06/23 16:21:20 by mdegache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

long	ft_atol(const char *nptr)
{
	int		i;
	long	nb;
	int		sign;

	sign = 1;
	nb = 0;
	i = 0;
	while ((nptr[i] > 8 && nptr[i] < 14) || nptr[i] == 32)
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -sign;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		nb = nb * 10 + (nptr[i] - '0');
		i++;
	}
	return (nb * sign);
}

int	ft_isdigit(int i)
{
	if (i >= 48 && i <= 57)
		return (2048);
	return (0);
}

long long	timestamp(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

int	ft_usleep(int ms, t_philo *philo)
{
	long long	time;
	long long	print_time;
	long long	actual_time;
	
	time = timestamp();
	print_time = time - philo->arg->time_start;
	actual_time = print_time - philo->time_leat;
	// printf("%d = %d\n", philo->name, philo->time_leat);
	// printf("%d = %lld\n", philo->name, actual_time + ms);
	if (actual_time + ms <= philo->arg->time_d)
	{	
		while (timestamp() - time < ms)
			usleep(ms / 10);
	}
	else
	{
		while ((timestamp() - philo->arg->time_start) - print_time < philo->arg->time_d - actual_time)
			usleep(ms /10);
		print(philo, "died");
		pthread_mutex_lock(&philo->arg->die);
		philo->arg->is_dead = 1;
		pthread_mutex_unlock(&philo->arg->die);
	}
	return (0);
}
