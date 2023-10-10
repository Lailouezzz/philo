/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-boud <ale-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 13:00:24 by ale-boud          #+#    #+#             */
/*   Updated: 2023/10/10 10:52:59 by ale-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_init(t_philoctx *ctx, int argc, char **argv)
{
	ctx->pn = argv[PROG_NAME];
	if (!ft_atoui(argv[PROG_NBPHILO], &ctx->nb))
		error(ctx, "number_of_philosophers must be an natural integer");
	if (!ft_atot(argv[PROG_TTODIE], &ctx->ttodie))
		error(ctx, "time_to_die must be an natural integer");
	if (!ft_atot(argv[PROG_TTOEAT], &ctx->ttoeat))
		error(ctx, "time_to_eat must be an natural integer");
	if (!ft_atot(argv[PROG_TTOSLEEP], &ctx->ttosleep))
		error(ctx, "time_to_sleep must be an natural integer");
	if (argc == PROG__MAX && !ft_atoui(argv[PROG_TTOEACHP], &ctx->ttoeach))
		error(ctx, "number_of_times_each_philosopher_must_eat \
must be an natural integer");
	else
		ctx->ttoeach = -1;
	ctx->write = NULL;
}
