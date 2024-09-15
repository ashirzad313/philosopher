/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manager.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashirzad <ashirzad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 11:57:35 by ashirzad          #+#    #+#             */
/*   Updated: 2024/09/15 18:41:04 by ashirzad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	*manager(void *pointer);
int		ft_eat(t_philo *philo);
int		ft_sleep(t_philo *philo);
int		ft_think(t_philo *philo);

void	*manager(void *pointer)
{
	t_philo	*philo;

	philo = (t_philo *)pointer;
	if (philo->id % 2 == 0)
		ft_usleep(philo->obj->t_eat - 10);
	while (end(philo->obj) == 0)
	{
		if (ft_eat(philo) == 0)
			break ;
		if (end(philo->obj) == 1)
			break ;
		if (ft_sleep(philo) == 0)
			break ;
		if (end(philo->obj) == 1)
			break ;
		if (ft_think(philo) == 0)
			break ;
	}
	return (NULL);
}

int	ft_eat(t_philo *philo)
{
	if (end(philo->obj) == 1)
		return (0);
	if (take_forks(philo, philo->obj->philo_mems) == 0)
		return (0);
	pthread_mutex_lock(&philo->eat_mutex);
	ft_print(*philo, EAT);
	ft_usleep(philo->obj->t_eat);
	update_last_time_meal(philo);
	philo->meal_numbers += 1;
	release_forks(philo);
	pthread_mutex_unlock(&philo->eat_mutex);
	return (1);
}

int	ft_sleep(t_philo *philo)
{
	if (end(philo->obj) == 1)
		return (0);
	ft_print(*philo, SLEEP);
	ft_usleep(philo->obj->t_sleep);
	return (1);
}

int	ft_think(t_philo *philo)
{
	if (end(philo->obj) == 1)
		return (0);
	ft_print(*philo, THINK);
	return (1);
}
