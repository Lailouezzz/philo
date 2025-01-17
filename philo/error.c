/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-boud <ale-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 10:36:02 by ale-boud          #+#    #+#             */
/*   Updated: 2023/12/13 18:45:46 by ale-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

noreturn void	error(t_philo_ctx *ctx, const char *s)
{
	philo_destroy(ctx);
	ft_putstr_fd(STDERR_FILENO, ctx->pn);
	ft_putstr_fd(STDERR_FILENO, ": ");
	ft_putstr_fd(STDERR_FILENO, s);
	ft_putstr_fd(STDERR_FILENO, "\n");
	exit(EXIT_FAILURE);
}
