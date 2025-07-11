/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdegache <mdegache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 09:28:32 by mdegache          #+#    #+#             */
/*   Updated: 2025/06/25 10:59:39 by mdegache         ###   ########.fr       */
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
	struct s_philo	*prev;
	struct s_philo	*next;
	struct s_param	*arg;
	pthread_t		thread;
	pthread_mutex_t	fork;
}	t_philo;

typedef struct s_param
{
	int				nb_philo;
	int				time_d;
	int				time_e;
	int				time_s;
	int				nb_dish;
	long long		time_start;
	int				is_dead;
	pthread_mutex_t	die;
	pthread_mutex_t	print;
	pthread_mutex_t	eat;
	t_philo			*philos;
}	t_param;

///*main.c*///

void		free_all(t_param *arg);

///*init_arg.c*///

int			verif_arg(int ac, char **av);
int			check_over(int ac, t_param *arg);
int			init_arg(int ac, char **av, t_param *arg);

///*utils.c*///

long		ft_atol(const char *nptr);
int			ft_isdigit(int i);
long long	timestamp(void);
int			ft_usleep(int ms, t_philo *philo);
int			check_is_dead(t_philo *philo);
void	ft_wait(t_philo *philo);

///*init_philo.c*///

void		*routine_funct(void *lst);
void		start_routine(t_philo *philo);
int			init_philo(t_param *arg);

///*lst_philo.c*///

void		last_next(t_philo *lst);
t_philo		*ft_lstnew(int i, t_param *arg);
void		ft_lstadd_back(t_philo **lst, t_philo *new);
void		ft_lstdelone(t_philo *lst);
void		ft_lstclear(t_philo **lst, t_param *arg);

///*routine.c*///

int			check_death(t_philo *philo);
int			eat(t_philo *philo);
void		print(t_philo *philo, char *str);
int			take_fork(t_philo *philo);

#endif