/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_start.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-boud <ale-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 19:29:32 by ale-boud          #+#    #+#             */
/*   Updated: 2023/12/13 22:45:05 by ale-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	_philo_wait_thread(t_philo_ctx *ctx)
{
	size_t	k;

	k = 0;
	while (k < ctx->nb)
	{
		if (ctx->philos[k].thread_id != 0)
			pthread_join(ctx->philos[k].thread_id, NULL);
		++k;
	}
}

static void	_philo_check_each(t_philo_ctx *ctx)
{
	size_t			k;
	unsigned int	nb_ate;

	k = 0;
	while (k < ctx->nb && ctx->t_toeach != __INT_MAX__)
	{
		pthread_mutex_lock(&ctx->philos[k].eaten);
		nb_ate = ctx->philos[k].nb_ate;
		pthread_mutex_unlock(&ctx->philos[k].eaten);
		if (nb_ate < (unsigned int) ctx->t_toeach)
			break ;
		++k;
	}
	if (k == ctx->nb)
		philo_set_running(ctx, 0);
}

static void	_philo_died(t_philo_ctx *ctx)
{
	size_t	k;

	while (philo_is_running(ctx))
	{
		k = 0;
		while (k < ctx->nb)
		{
			pthread_mutex_lock(&ctx->philos[k].eating);
			if (ft_time_ms() - ctx->philos[k].last_eat >= ctx->t_todie)
			{
				philo_set_running(ctx, 0);
				philo_log(ctx, k, LOG_DIED);
				exit(EXIT_FAILURE);
				pthread_mutex_unlock(&ctx->philos[k].eating);
				break ;
			}
			pthread_mutex_unlock(&ctx->philos[k].eating);
			++k;
		}
		_philo_check_each(ctx);
	}
}

void	philo_start(t_philo_ctx *ctx)
{
	size_t	k;

	ctx->is_running = 1;
	k = 0;
	while (k < ctx->nb)
	{
		ctx->philos[k].last_eat = ft_time_ms();
		if (pthread_create(&ctx->philos[k].thread_id, NULL,
				philo_life, &ctx->philos[k]))
		{
			philo_set_running(ctx, 0);
			_philo_wait_thread(ctx);
			error(ctx, "Thread init error");
		}
		usleep(500);
		++k;
	}
	_philo_died(ctx);
	_philo_wait_thread(ctx);
}
