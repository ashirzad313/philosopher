/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashirzad <ashirzad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 14:03:42 by ashirzad          #+#    #+#             */
/*   Updated: 2024/09/15 18:41:10 by ashirzad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	ft_usleep(int long miliseconds)
{
	int long	start;

	start = current_time();
	while ((current_time() - start) < miliseconds)
		usleep(500);
	return (0);
}

int long	current_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		write(2, "gettimeofday() error\n", 22);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}
