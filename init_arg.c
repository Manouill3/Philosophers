/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_arg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdegache <mdegache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 11:12:14 by mdegache          #+#    #+#             */
/*   Updated: 2025/06/13 08:36:16 by mdegache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int verif_arg(int ac, char **av)
{
	int i;
	int j;

	i = 1;
	while (i < ac)
	{
		j = 0;
		while (av[i][j])
		{
			if (!ft_isdigit(av[i][j]) && av[i][j] != '+')
				return (1);
			if (av[i][j] == '+' && (av[i][j] == '+' || av[i][j] == '-'))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_over(int ac, t_param *arg)
{
	if (ac == 6)
	{
		if (arg->nb_dish < 1 || arg->nb_dish > 2147483647)
			return (1);
	}
	if (arg->nb_philo < 1 || arg->nb_philo > 2147483647)
			return (1);
	if (arg->time_d < 1 || arg->time_d > 2147483647)
			return (1);
	if (arg->time_e < 1 || arg->time_e > 2147483647)
			return (1);
	if (arg->time_s < 1 || arg->time_s > 2147483647)
			return (1);
	return (0);
}

int init_arg(int ac, char **av, t_param *arg)
{
	if (verif_arg(ac, av))
		return (1);
	if (ac == 6)
		arg->nb_dish = ft_atol(av[5]);
	arg->nb_philo = ft_atol(av[1]);
	arg->time_d = ft_atol(av[2]);
	arg->time_e = ft_atol(av[3]);
	arg->time_s = ft_atol(av[4]);
	if (check_over(ac, arg))
		return (1);
	pthread_mutex_init(&arg->print, NULL);
	return (0);
}
