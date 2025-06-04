/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdegache <mdegache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 09:28:32 by mdegache          #+#    #+#             */
/*   Updated: 2025/06/04 14:08:40 by mdegache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>

typedef struct s_philo
{
	
} t_philo;

typedef struct s_param
{
	int nb_philo;
	int time_d;
	int time_e;
	int time_s;
	int nb_dish;
} t_param;

///*init.c*///

int verif_arg(int ac, char **av);
int init_arg(int ac, char **av, t_param *arg);

///*libft_funct.c*///

long	ft_atoi(const char *nptr);
int	ft_isdigit(int i);

#endif