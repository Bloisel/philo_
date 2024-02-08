/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bloisel <bloisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 13:35:20 by bloisel           #+#    #+#             */
/*   Updated: 2023/10/20 17:00:53 by bloisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# define MAX 2147483647

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct t_phil
{
	int															*stop;
	int															id;
	int															*compteur;
	int															nb_m_eat;
	int															phi_a_eat;
	int															count;
	int															nb_philo;
	int															time_to_eat;
	int															time_to_die;
	int															time_to_sleep;
	int															left_fork;
	int															right_fork;
	long long													*last_eat;
	long long													time_to_start;
	pthread_mutex_t												*fork;
	pthread_mutex_t												*print;
	pthread_mutex_t												*glob;
	pthread_t													t;
}	t_philo;
typedef struct t_info
{
	int															*stop;
	int															nb_philo;
	int															time_to_eat;
	int															time_to_die;
	int															time_to_sleep;
	int															phi_a_eat;
	int															nb_m_eat;
	int															*compteur;
	long long													time_to_start;
	pthread_mutex_t												*fork;
	pthread_mutex_t												*print;
	pthread_mutex_t												*glob;
	t_philo														**phiphi;
}	t_inf;

void								ft_usleep(long long milis, t_philo *info);
void								init_phiphi(t_inf *info);
int									init_philo(t_inf *info);
int									init_mutex(t_inf *info);
int									init_struct(t_inf *info, char **argv);
void								*thread_routine(void *philo_struct);
void								init_thread(t_inf *info);
void								init_thread(t_inf *info);
void								print_val(char *str, t_philo *info);
int									check_end(t_philo *data);
int									checkar(char **argv);
void								free_resources(t_inf *inf);
long long							timeval(void);
int									check_num(char **str);
int									ft_isdigit(int character);
long								ft_atoi(const char *str);
int									check_max(char **str);

#endif
