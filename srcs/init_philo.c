/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bloisel <bloisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 16:56:46 by bloisel           #+#    #+#             */
/*   Updated: 2023/10/19 17:19:47 by bloisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	init_phiphi2(t_inf *info)
{
	int	i;

	i = -1;
	while (++i < info->nb_philo)
	{
		info->phiphi[i]->count = 0;
		info->phiphi[i]->compteur = info->compteur;
		info->phiphi[i]->print = info->print;
		info->phiphi[i]->glob = info->glob;
		if (info->phiphi[i]->id == info->nb_philo)
			info->phiphi[i]->right_fork = 0;
		else
			info->phiphi[i]->right_fork = i + 1;
		info->phiphi[i]->left_fork = i;
	}
}

void	init_phiphi(t_inf *info)
{
	int	i;

	i = -1;
	while (++i < info->nb_philo)
	{
		info->phiphi[i]->id = i + 1;
		info->phiphi[i]->nb_philo = info->nb_philo;
		info->phiphi[i]->time_to_die = info->time_to_die;
		info->phiphi[i]->time_to_eat = info->time_to_eat;
		info->phiphi[i]->time_to_sleep = info->time_to_sleep;
		info->phiphi[i]->nb_m_eat = info->nb_m_eat;
		info->phiphi[i]->phi_a_eat = info->phi_a_eat;
		info->phiphi[i]->fork = info->fork;
		info->phiphi[i]->time_to_start = info->time_to_start;
		info->phiphi[i]->last_eat[0] = info->time_to_start;
		info->phiphi[i]->stop = info->stop;
	}
	init_phiphi2(info);
}

int	init_philo(t_inf *info)
{
	int	i;

	info->phiphi = malloc(sizeof(t_philo *) * info->nb_philo);
	if (info->phiphi == NULL)
		return (1);
	i = -1;
	while (++i < info->nb_philo)
	{
		info->phiphi[i] = malloc(sizeof(t_philo));
		if (info->phiphi[i] == NULL)
			return (1);
		info->phiphi[i]->last_eat = malloc(sizeof(time_t));
		if (info->phiphi[i]->last_eat == NULL)
			return (1);
	}
	init_phiphi(info);
	return (0);
}
