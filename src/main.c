/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashirzad <ashirzad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 12:13:35 by ashirzad          #+#    #+#             */
/*   Updated: 2024/09/15 18:41:00 by ashirzad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	check_args(int args, char **argv)
{
	if (args == 5 || args == 6)
	{
		if (ft_atoi(argv[1]) > 0 && ft_atoi(argv[1]) <= 200 \
			&& ft_atoi(argv[2]) >= 60 && ft_atoi(argv[3]) \
			>= 60 && ft_atoi(argv[4]) >= 60 && ft_atoi(argv[5]) >= 0)
		{
			if (ft_atoi(argv[1]) == 1)
			{
				printf("%ld 1 died\n", ft_atoi(argv[2]));
				return (0);
			}
			return (1);
		}
	}
	printf("Wrong input!\n\n");
	printf("./philo nb_philos time_to_die time_to_eat time_to_sleep\n\n");
	printf("Example:\n\n");
	printf("./philo 5 2000 500 500\n\n");
	printf("nb_philos 1-200\n");
	printf("time_to_die > 60\n");
	printf("time_to_eat > 60\n");
	printf("time_to_sleep > 60\n");
	printf("optional arg number of meals > 0");
	return (0);
}

int	main(int args, char **argv)
{
	t_obj	obj;

	if (!check_args(args, argv))
		return (1);
	init_obj(&obj, argv);
	init_philo(&obj);
	create_threads(&obj);
	join_threads(&obj);
	free_data(&obj);
	return (0);
}
