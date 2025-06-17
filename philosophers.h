/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdegache <mdegache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 09:28:32 by mdegache          #+#    #+#             */
/*   Updated: 2025/06/17 14:04:15 by mdegache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <sys/time.h>

typedef struct s_philo
{
	int				name;
	int				count_dish;
	int				time_leat;
	struct s_philo 	*prev;
	struct s_philo	*next;
	struct s_param	*arg;
	pthread_t		thread;
	pthread_mutex_t fork;
} t_philo;

typedef struct s_param
{
	int 		nb_philo;
	int 		time_d;
	int 		time_e;
	int 		time_s;
	int 		nb_dish;
	int			time_start;
	pthread_mutex_t	print;
	pthread_mutex_t eat;
	t_philo		*philos;
} t_param;

///*main.c*///

void	free_all(t_param *arg);

///*init_arg.c*///

int verif_arg(int ac, char **av);
int	check_over(int ac, t_param *arg);
int init_arg(int ac, char **av, t_param *arg);

///*utils.c*///

long	ft_atol(const char *nptr);
int	ft_isdigit(int i);
int	timestamp(void);
void	ft_usleep(int ms);

///*init_philo.c*///

void	*routine_funct(void *lst);
void	start_routine(t_philo *philos);
int    init_philo(t_param *arg);

///*lst_philo.c*///

void	last_next(t_philo *lst);
t_philo	*ft_lstnew(int i, t_param *arg);
void	ft_lstadd_back(t_philo **lst, t_philo *new);
void	ft_lstdelone(t_philo *lst);
void	ft_lstclear(t_philo **lst, t_param *arg);

///*routine.c*///

int	check_death(t_philo *philo);
void	eat(t_philo *philos);
void	print(t_philo *philos, char *str);
int    take_fork(t_philo *philos);

#endif