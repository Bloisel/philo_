/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_thread.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bloisel <bloisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 16:55:48 by bloisel           #+#    #+#             */
/*   Updated: 2023/10/20 05:09:27 by bloisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	init_thread2(t_inf *info, int i)
{
	while (1)
	{
		usleep(50);
		while (++i < info->nb_philo)
		{
			pthread_mutex_lock(&info->glob[0]);
			if (info->compteur[0] == info->nb_philo)
			{
				pthread_mutex_unlock(&info->glob[0]);
				return ;
			}
			if ((info->stop[0] != 1) && (info->time_to_die <= (timeval()
						- info->phiphi[i]->last_eat[0])))
			{
				info->phiphi[i]->stop[0] = 1;
				printf("%lld %d died\n", timeval()
					- info->time_to_start, info->phiphi[i]->id);
			}
			pthread_mutex_unlock(&info->glob[0]);
		}
		i = -1;
	}
	return ;
}

void	init_thread(t_inf *info)
{
	int			i;

	i = 0;
	while (i < info->nb_philo)
	{
		if (pthread_create(&info->phiphi[i]->t, NULL,
				thread_routine, info->phiphi[i]) != 0)
			return ;
		i++;
		usleep(20);
	}
	i = 0;
	while (i < info->nb_philo)
	{
		pthread_detach(info->phiphi[i]->t);
		i++;
	}
	i = -1;
	init_thread2(info, i);
}
