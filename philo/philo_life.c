/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_life.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-boud <ale-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 19:32:20 by ale-boud          #+#    #+#             */
/*   Updated: 2023/12/13 22:17:00 by ale-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "philo.h"

void	*philo_life(void *p)
{
	t_philo *const		philo = p;
	t_philo_ctx *const	ctx = philo->ctx;

	if (philo->id % 2)
		custom_sleep(philo, 4);
	while (philo_is_running(ctx))
	{
		philo_eat(philo);
		if (!philo_is_running(philo->ctx))
			break ;
		philo_log(ctx, philo->id, LOG_SLEEPING);
		custom_sleep(philo, ctx->t_tosleep);
		philo_log(ctx, philo->id, LOG_THINKING);
	}
	return (NULL);
}
