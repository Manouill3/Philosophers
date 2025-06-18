/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 13:38:01 by mdegache          #+#    #+#             */
/*   Updated: 2025/06/18 19:40:55 by marvin           ###   ########.fr       */
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

int	timestamp(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

int	ft_usleep(int ms, t_philo *philo)
{
	int	diff;
	int	time;
	int	tmp;

	tmp = 0;
	time = timestamp();
	diff = time - philo->time_leat;
	while (timestamp() - time < ms)
	{
		tmp += ms / 10;
		usleep(ms / 10);
		if (ms == philo->arg->time_d && philo->arg->time_d != philo->arg->time_s
			&& tmp + diff > philo->arg->time_d)
			return (1);
	}
	return (0);
}
