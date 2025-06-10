/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdegache <mdegache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 09:26:37 by mdegache          #+#    #+#             */
/*   Updated: 2025/06/10 14:42:35 by mdegache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "philosophers.h"

int main(int ac, char **av)
{
	t_param *arg;
	
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
		return (1);
	}
	if (init_philo(arg))
	{
		free(arg);
		return ;
	}
	free(arg);
	return (0);
}
