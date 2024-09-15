/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashirzad <ashirzad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 12:21:08 by ashirzad          #+#    #+#             */
/*   Updated: 2024/09/15 18:41:14 by ashirzad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	ft_print(t_philo philo, int n)
{
	if (n == SLEEP)
		printf("%ld %d is sleeping\n", \
		current_time() - philo.obj->start, philo.id);
	else if (n == EAT)
		printf("%ld %d is eating\n", current_time() \
		- philo.obj->start, philo.id);
	else if (n == DIED)
	{
		printf("%ld %d died\n", current_time() - \
		philo.obj->start, philo.id);
	}
	else if (n == THINK)
		printf("%ld %d is thinking\n", current_time() \
		- philo.obj->start, philo.id);
	else if (n == LEFT_FORK)
		printf("%ld %d has taken left fork\n", current_time() \
		- philo.obj->start, philo.id);
	else if (n == RIGHT_FORK)
		printf("%ld %d has taken right fork\n", current_time() \
		- philo.obj->start, philo.id);
}

int	take_forks(t_philo *philo, int len)
{
	if (pthread_mutex_lock(&philo->obj->forks[(philo->id - 1) % len]) == 0)
	{
		if (end(philo->obj) == 1)
		{
			pthread_mutex_unlock(&philo->obj->forks[(philo->id - 1) % len]);
			return (0);
		}
		if (pthread_mutex_lock(&philo->obj->forks[philo->id % len]) == 0)
		{
			if (end(philo->obj) == 1)
			{
				release_forks(philo);
				return (0);
			}
			ft_print(*philo, LEFT_FORK);
			ft_print(*philo, RIGHT_FORK);
			return (1);
		}
		else
			pthread_mutex_unlock(&philo->obj->forks[(philo->id - 1) % len]);
	}
	return (0);
}

int	release_forks(t_philo *philo)
{
	int	left_fork;
	int	right_fork;

	left_fork = (philo->id - 1) % philo->obj->philo_mems;
	right_fork = philo->id % philo->obj->philo_mems;
	pthread_mutex_unlock(&philo->obj->forks[left_fork]);
	pthread_mutex_unlock(&philo->obj->forks[right_fork]);
	return (1);
}

int long	ft_atoi(char *str)
{
	int long	result;

	if (str == NULL)
		return (0);
	result = 0;
	while (*str)
	{
		result = (result * 10) + (*str - 48);
		str++;
	}
	return (result);
}
