/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdegache <mdegache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 14:01:22 by mdegache          #+#    #+#             */
/*   Updated: 2025/06/23 15:27:47 by mdegache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*routine_funct(void *lst)
{
	t_philo	*philo;
	
	philo = (t_philo *)lst;
	if (philo->name % 2 != 0)
		ft_usleep(philo->arg->time_e / 2, philo);
	while (!philo->arg->is_dead)
	{
		if (take_fork(philo))
			break ;
		if (eat(philo))
			break ;
		if (check_death(philo))
			break ;
		if (philo->count_dish == philo->arg->nb_dish)
			break ;
	}
	return (NULL);
}

void	start_routine(t_philo *philos)
{
	int	i;
	t_philo	*tmp;

	i = 0;
	tmp = philos;
	while (tmp->arg->nb_philo > i)
	{
		pthread_create(&tmp->thread, NULL, routine_funct, tmp);
		tmp = tmp->next;
		i++;
	}
	i = 0;
	tmp = philos;
	while (tmp->arg->nb_philo > i)
	{
		pthread_join(tmp->thread, NULL);
		tmp = tmp->next;
		i++;
	}
}

int    init_philo(t_param *arg)
{
	int i;
	t_philo *node;

	i = 0;
	arg->is_dead = 0;
	arg->philos = NULL;
	arg->time_start = timestamp();
	while (i < arg->nb_philo)
	{
		node = ft_lstnew(i, arg);
		if (!node)
			return (1);
		ft_lstadd_back(&arg->philos, node);
		i++;
	}
	last_next(arg->philos);
	start_routine(arg->philos);
	return (0);
}
