/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashirzad <ashirzad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 10:05:20 by ashirzad          #+#    #+#             */
/*   Updated: 2024/09/15 18:40:56 by ashirzad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	init_obj(t_obj *obj, char **argv)
{
	obj->philo_mems = (int)ft_atoi(argv[1]);
	obj->died = 0;
	obj->mont = 0;
	obj->t_die = ft_atoi(argv[2]);
	obj->t_eat = ft_atoi(argv[3]);
	obj->t_sleep = ft_atoi(argv[4]);
	obj->start = current_time();
	obj->threads = malloc(sizeof(pthread_t) * obj->philo_mems);
	obj->philo = malloc(sizeof(t_philo) * obj->philo_mems);
	obj->forks = malloc(sizeof(pthread_mutex_t) * obj->philo_mems);
	obj->meals_to_have = -1;
	if (argv[5] != NULL)
		obj->meals_to_have = (int)ft_atoi(argv[5]);
	pthread_mutex_init(&obj->died_mutex, NULL);
	pthread_mutex_init(&obj->meal_len, NULL);
}

void	init_philo(t_obj *obj)
{
	int	i;

	i = 0;
	while (i < obj->philo_mems)
	{
		obj->philo[i].id = i + 1;
		obj->philo[i].meal_numbers = 0;
		obj->philo[i].last_time_ml = current_time();
		pthread_mutex_init(&obj->forks[i], NULL);
		pthread_mutex_init(&obj->philo[i].eat_mutex, NULL);
		pthread_mutex_init(&obj->philo[i].sleep_mutex, NULL);
		pthread_mutex_init(&obj->philo[i].meal_mutex, NULL);
		obj->philo[i].obj = obj;
		i++;
	}
}
