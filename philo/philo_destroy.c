/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_destroy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-boud <ale-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 18:35:28 by ale-boud          #+#    #+#             */
/*   Updated: 2023/12/13 22:02:08 by ale-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_destroy(t_philo_ctx *ctx)
{
	size_t	k;

	if (ctx->forks != NULL)
	{
		k = 0;
		while (k < ctx->nb)
			pthread_mutex_destroy(&ctx->forks[k++]);
		free(ctx->forks);
	}
	if (ctx->philos != NULL)
	{
		k = 0;
		while (k < ctx->nb)
		{
			pthread_mutex_destroy(&ctx->philos[k].eating);
			pthread_mutex_destroy(&ctx->philos[k].eaten);
			++k;
		}
		free(ctx->philos);
	}
	pthread_mutex_destroy(&ctx->mis_running);
}
