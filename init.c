/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdegache <mdegache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 11:12:14 by mdegache          #+#    #+#             */
/*   Updated: 2025/06/04 14:08:55 by mdegache         ###   ########.fr       */
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
			if (!ft_isdigit(av[i][j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int init_arg(int ac, char **av, t_param *arg)
{
	if (verif_arg(ac, av))
		return (1);
	if (ac == 6)
		arg->nb_dish = ft_atoi(av[5]);
	arg->nb_philo = ft_atoi(av[1]);
	arg->time_d = ft_atoi(av[2]);
	arg->time_e = ft_atoi(av[3]);
	arg->time_s = ft_atoi(av[4]);
	return (0);
}
