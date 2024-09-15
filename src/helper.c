/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashirzad <ashirzad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 12:02:39 by ashirzad          #+#    #+#             */
/*   Updated: 2024/09/15 18:40:53 by ashirzad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	update_last_time_meal(t_philo *philo)
{
	pthread_mutex_lock(&philo->meal_mutex);
	philo->last_time_ml = current_time();
	pthread_mutex_unlock(&philo->meal_mutex);
}

int	is_eating(t_obj *obj, int i)
{
	if (pthread_mutex_lock(&obj->philo[i].eat_mutex) == 0)
	{
		pthread_mutex_unlock(&obj->philo[i].eat_mutex);
		return (0);
	}
	return (1);
}

int	is_died(t_philo philo)
{
	if (current_time() - philo.last_time_ml >= philo.obj->t_die)
		return (1);
	return (0);
}

int	monitor(t_obj *obj)
{
	int		i;
	int		count;

	if (obj->mont == 1)
		return (0);
	pthread_mutex_lock(&obj->meal_len);
	i = 0;
	count = 0;
	while (i < obj->philo_mems)
	{
		count += obj->philo[i].meal_numbers;
		i++;
	}
	pthread_mutex_unlock(&obj->meal_len);
	if (count == (obj->meals_to_have * obj->philo_mems))
	{
		obj->mont = 1;
		return (0);
	}
	return (1);
}

int	end(t_obj *obj)
{
	int	i;

	i = 0;
	if (obj->died == 1 || obj->mont == 1)
		return (1);
	pthread_mutex_lock(&obj->died_mutex);
	while (i < obj->philo_mems)
	{
		if (monitor(obj) == 0)
		{
			pthread_mutex_unlock(&obj->died_mutex);
			return (1);
		}
		if (is_died(obj->philo[i]) == 1 && !is_eating(obj, i))
		{
			if (obj->died != 1)
				ft_print(obj->philo[i], DIED);
			obj->died = 1;
			pthread_mutex_unlock(&obj->died_mutex);
			return (1);
		}
		i++;
	}
	pthread_mutex_unlock(&obj->died_mutex);
	return (0);
}
