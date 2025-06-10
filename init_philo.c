/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdegache <mdegache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 14:01:22 by mdegache          #+#    #+#             */
/*   Updated: 2025/06/10 14:40:10 by mdegache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int    init_philo(t_param *arg)
{
	int i;
	t_philo *node;

	i = 0;
	arg->philos = malloc(sizeof(t_philo));
	if (!arg->philos)
		return (1);
	while (i < arg->nb_philo)
	{
		node = ft_lstnew(i);
		if (!node)
			return (1);
		ft_lstadd_back(&arg->philos, node);
		i++;
	}
	last_next(arg->nb_philo);
	return (0);
}
