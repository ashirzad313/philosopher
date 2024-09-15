/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashirzad <ashirzad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 17:54:56 by ashirzad          #+#    #+#             */
/*   Updated: 2024/05/05 14:30:04 by ashirzad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include <stdlib.h>

# define DIED 0
# define EAT 1
# define SLEEP 2
# define THINK 3
# define LEFT_FORK 4
# define RIGHT_FORK 5

struct	s_obj;

typedef struct s_philo
{
	struct s_obj	*obj;
	pthread_mutex_t	eat_mutex;
	pthread_mutex_t	sleep_mutex;
	pthread_mutex_t	meal_mutex;
	int long		last_time_ml;
	int				meal_numbers;
	int				id;
}	t_philo;

typedef struct s_obj
{
	pthread_mutex_t	meal_len;
	pthread_t		*threads;
	t_philo			*philo;
	pthread_mutex_t	*forks;
	pthread_mutex_t	died_mutex;
	int long		t_die;
	int long		t_eat;
	int long		t_sleep;
	int long		start;
	int				philo_mems;
	int				meals_to_have;
	int				died;
	int				mont;
}	t_obj;

//initilze values for struct
void		init_obj(t_obj *obj, char **argv);
void		init_philo(t_obj *obj);

//utils.c
int			ft_usleep(int long miliseconds);
int long	ft_atoi(char *str);
int long	current_time(void);
int			take_forks(t_philo *philo, int len);
int			release_forks(t_philo *philo);

// all threads realted creating join nd freeing the mutex
void		create_threads(t_obj *obj);
void		join_threads(t_obj *obj);
void		free_data(t_obj *obj);

// the functions thta help manager
int			monitor(t_obj *obj);
void		ft_print(t_philo philo, int n);
void		update_last_time_meal(t_philo *philo);
int			end(t_obj *obj);
int			is_died(t_philo philo);
int			is_eating(t_obj *obj, int i);

//manager of the table
void		*manager(void *pointer);
int			ft_eat(t_philo *philo);
int			ft_sleep(t_philo *philo);
int			ft_think(t_philo *philo);

#endif
