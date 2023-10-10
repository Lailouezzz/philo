/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philolog.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-boud <ale-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 13:03:50 by ale-boud          #+#    #+#             */
/*   Updated: 2023/10/10 12:40:15 by ale-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_log(t_philoctx *ctx, time_t t, int nb, t_logtype type)
{
	static pthread_mutex_t	mut = PTHREAD_MUTEX_INITIALIZER;

	if (pthread_mutex_lock(&mut) != 0)
		thread_error(ctx, "mutex lock error");
	ft_putstr_fd(STDOUT_FILENO, "test\n");
	if (pthread_mutex_unlock(&mut) != 0)
		thread_error(ctx, "mutex unlock error");
}
