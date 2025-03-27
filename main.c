/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdegache <mdegache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 09:26:37 by mdegache          #+#    #+#             */
/*   Updated: 2025/03/27 10:27:03 by mdegache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "philosophers.h"

void *routine(void *arg)
{
    t_philo *philo = (t_philo *)arg;
    
    pthread_mutex_lock(&philo->left_fork);
    printf("Thread %ld en section critique\n", pthread_self());
    sleep(1);
    printf("Thread %ld sort de la section critique\n", pthread_self());
    pthread_mutex_unlock(&philo->left_fork);
    return (NULL);
}

void test_thread(t_philo *philo)
{
    pthread_t thread;
    pthread_t thread2;
    
    philo->id = 1;
    if (pthread_mutex_init(&philo->left_fork, NULL) != 0)
    {
        printf("Error: mutex init failed\n");
        return ;
    }
    pthread_create(&thread, NULL, routine, philo);
    pthread_create(&thread2, NULL, routine, philo);
    
    pthread_join(thread2, NULL);
    pthread_join(thread, NULL);
    
    pthread_mutex_destroy(&philo->left_fork);
}

void init_philo(t_philo *philo)
{
    philo = malloc(sizeof(t_philo));
}

int main(int ac, char **av)
{
    t_philo philo;
    
    if (ac != 5 && ac != 6)
    {
        printf("Error: wrong number of arguments\n");
        return (1);
    }
    init_philo(&philo);
    philo.time_to_die = atoi(av[2]);
    philo.time_to_eat = atoi(av[3]);
    philo.time_to_sleep = atoi(av[4]);
    if (ac == 6)
        philo.nb_meals = atoi(av[5]);
    else
        philo.nb_meals = -1;
    test_thread(&philo);    
    return (0);
}
