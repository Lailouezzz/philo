/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   custom_sleep.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-boud <ale-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 19:54:20 by ale-boud          #+#    #+#             */
/*   Updated: 2023/12/13 22:03:25 by ale-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "philo.h"

void	custom_sleep(t_philo *philo, time_t duration)
{
	time_t	now;

	now = ft_time_ms();
	while (now + duration > ft_time_ms())
	{
		if (!philo_is_running(philo->ctx))
			break ;
		usleep(((t_philo_ctx *)philo->ctx)->nb * 2);
	}
}
