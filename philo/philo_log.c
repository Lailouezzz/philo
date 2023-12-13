/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_log.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-boud <ale-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 13:03:50 by ale-boud          #+#    #+#             */
/*   Updated: 2023/12/13 22:03:01 by ale-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static const char	*_philo_log(t_log_type type)
{
	if (type == LOG_FORK_TAKEN)
		return ("has taken a fork");
	if (type == LOG_EATING)
		return ("is eating");
	if (type == LOG_SLEEPING)
		return ("is sleeping");
	if (type == LOG_THINKING)
		return ("is thinking");
	if (type == LOG_DIED)
		return ("died");
	return ("");
}

void	philo_log(t_philo_ctx *ctx, int nb, t_log_type type)
{
	static pthread_mutex_t	mut = PTHREAD_MUTEX_INITIALIZER;

	pthread_mutex_lock(&mut);
	if (philo_is_running(ctx) || type == LOG_DIED)
		printf("%-8ld%d %s\n", ft_time_ms(), nb, _philo_log(type));
	pthread_mutex_unlock(&mut);
}

int	philo_is_running(t_philo_ctx *ctx)
{
	int	isrun;

	pthread_mutex_lock(&ctx->mis_running);
	isrun = ctx->is_running;
	pthread_mutex_unlock(&ctx->mis_running);
	return (isrun);
}

void	philo_set_running(t_philo_ctx *ctx, int run)
{
	pthread_mutex_lock(&ctx->mis_running);
	ctx->is_running = run;
	pthread_mutex_unlock(&ctx->mis_running);
}
