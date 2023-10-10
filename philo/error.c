/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-boud <ale-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 10:36:02 by ale-boud          #+#    #+#             */
/*   Updated: 2023/10/10 10:56:37 by ale-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

noreturn void	error(t_philoctx *ctx, const char *s)
{
	ft_putstr_fd(STDERR_FILENO, ctx->pn);
	ft_putstr_fd(STDERR_FILENO, ": ");
	ft_putstr_fd(STDERR_FILENO, s);
	ft_putstr_fd(STDERR_FILENO, "\n");
	exit(EXIT_FAILURE);
}
