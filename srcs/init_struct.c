/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bloisel <bloisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 16:56:41 by bloisel           #+#    #+#             */
/*   Updated: 2023/10/20 01:17:56 by bloisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	init_mutex(t_inf *info)
{
	int	i;

	i = 0;
	while (i < info->nb_philo)
	{
		if (pthread_mutex_init(&info->fork[i], NULL) != 0)
			return (1);
		i++;
	}
	if (pthread_mutex_init(&info->print[0], NULL) != 0)
		return (1);
	if (pthread_mutex_init(&info->glob[0], NULL) != 0)
		return (1);
	return (0);
}

int	init_struct(t_inf *info, char **argv)
{
	info->nb_philo = ft_atoi(argv[1]);
	info->time_to_die = ft_atoi(argv[2]);
	info->time_to_eat = ft_atoi(argv[3]);
	info->time_to_sleep = ft_atoi(argv[4]);
	if (argv[5] != 0)
		info->nb_m_eat = ft_atoi(argv[5]);
	info->time_to_start = timeval();
	info->phi_a_eat = 0;
	if (argv[5] == 0)
		info->nb_m_eat = -50;
	info->compteur = malloc(sizeof(int));
	info->stop = malloc(sizeof(int));
	info->fork = malloc(sizeof(pthread_mutex_t) * info->nb_philo);
	info->print = malloc(sizeof(pthread_mutex_t));
	info->glob = malloc(sizeof(pthread_mutex_t));
	info->compteur[0] = 0;
	info->stop[0] = 0;
	if (init_mutex(info) != 0)
		return (1);
	return (0);
}
