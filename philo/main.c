/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdegache <mdegache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 09:26:37 by mdegache          #+#    #+#             */
/*   Updated: 2025/06/24 09:33:04 by mdegache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	free_all(t_param *arg)
{
	if (arg->philos)
		ft_lstclear(&arg->philos, arg);
	pthread_mutex_destroy(&arg->print);
	pthread_mutex_destroy(&arg->eat);
	pthread_mutex_destroy(&arg->die);
	free(arg);
}

int	main(int ac, char **av)
{
	t_param	*arg;

	if (ac != 5 && ac != 6)
	{
		printf("Error: wrong number of arguments\n");
		return (1);
	}
	arg = malloc(sizeof(t_param));
	if (!arg)
		return (1);
	if (init_arg(ac, av, arg))
	{
		printf("Error: some bad arguments\n");
		free(arg);
		return (1);
	}
	if (init_philo(arg))
	{
		free_all(arg);
		return (1);
	}
	free_all(arg);
	return (0);
}
