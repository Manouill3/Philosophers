/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_philo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdegache <mdegache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 08:48:34 by mdegache          #+#    #+#             */
/*   Updated: 2025/06/24 08:12:07 by mdegache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

t_philo	*ft_lstnew(int i, t_param *arg)
{
	t_philo	*lst;

	lst = malloc(sizeof(t_philo));
	if (!lst)
		return (0);
	lst->name = i;
	lst->count_dish = 0;
	lst->time_leat = 0;
	lst->arg = arg;
	lst->prev = NULL;
	lst->next = NULL;
	if (pthread_mutex_init(&lst->fork, NULL))
	{
		free(lst);
		return (NULL);
	}
	return (lst);
}

void	ft_lstadd_back(t_philo **lst, t_philo *new)
{
	t_philo	*tmp;

	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	tmp = *lst;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
	new->prev = tmp;
}

void	ft_lstdelone(t_philo *lst)
{
	if (!lst)
		return ;
	pthread_mutex_destroy(&lst->fork);
	free(lst);
}

void	ft_lstclear(t_philo **lst, t_param *arg)
{
	int		i;
	t_philo	*tmp;

	if (!lst || !*lst)
		return ;
	i = 0;
	while (arg->nb_philo > i)
	{
		tmp = (*lst)->next;
		ft_lstdelone(*lst);
		*lst = tmp;
		i++;
	}
	*lst = NULL;
}

void	last_next(t_philo *lst)
{
	t_philo	*tmp;

	tmp = lst;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = lst;
	lst->prev = tmp;
}
