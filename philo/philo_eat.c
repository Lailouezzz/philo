/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_eat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-boud <ale-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 19:23:46 by ale-boud          #+#    #+#             */
/*   Updated: 2023/12/13 22:46:27 by ale-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	_philo_eat_take_rfork(t_philo *philo)
{
	pthread_mutex_lock(philo->r_fork);
	philo_log(philo->ctx, philo->id, LOG_FORK_TAKEN);
}

static void	_philo_eat_take_lfork(t_philo *philo)
{
	pthread_mutex_lock(philo->l_fork);
	philo_log(philo->ctx, philo->id, LOG_FORK_TAKEN);
}

static void	_philo_eat_take_fork(t_philo *philo)
{
	if (philo->id % 2)
	{
		_philo_eat_take_rfork(philo);
		_philo_eat_take_lfork(philo);
	}
	else
	{
		_philo_eat_take_lfork(philo);
		if (philo->l_fork != philo->r_fork)
			_philo_eat_take_rfork(philo);
	}
}

void	philo_eat(t_philo *philo)
{
	_philo_eat_take_fork(philo);
	if (philo->r_fork == philo->l_fork)
	{
		while (philo_is_running(philo->ctx))
			usleep(50);
		pthread_mutex_unlock(philo->l_fork);
		return ;
	}
	pthread_mutex_lock(&philo->eating);
	philo_log(philo->ctx, philo->id, LOG_EATING);
	philo->last_eat = ft_time_ms();
	pthread_mutex_unlock(&philo->eating);
	custom_sleep(philo, ((t_philo_ctx *)philo->ctx)->t_toeat);
	pthread_mutex_lock(&philo->eaten);
	++philo->nb_ate;
	pthread_mutex_unlock(&philo->eaten);
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
}
