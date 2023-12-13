/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-boud <ale-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 13:00:24 by ale-boud          #+#    #+#             */
/*   Updated: 2023/12/13 21:41:14 by ale-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_init_args(t_philo_ctx *ctx, int argc, char **argv)
{
	ctx->pn = argv[PROG_NAME];
	ctx->philos = NULL;
	ctx->is_running = 0;
	ctx->forks = NULL;
	if (!ft_atoui(argv[PROG_NBPHILO], &ctx->nb))
		error(ctx, "number_of_philosophers must be an natural integer");
	if (!ft_atot(argv[PROG_TTODIE], &ctx->t_todie))
		error(ctx, "time_to_die must be an natural integer");
	if (!ft_atot(argv[PROG_TTOEAT], &ctx->t_toeat))
		error(ctx, "time_to_eat must be an natural integer");
	if (!ft_atot(argv[PROG_TTOSLEEP], &ctx->t_tosleep))
		error(ctx, "time_to_sleep must be an natural integer");
	if (argc == PROG__MAX && !ft_atoui(argv[PROG_TTOEACHP], &ctx->t_toeach))
		error(ctx, "number_of_times_each_philosopher_must_eat \
must be an natural integer");
	else if (argc != PROG__MAX)
		ctx->t_toeach = __INT_MAX__;
	if (ctx->nb == 0)
		error(ctx, "number_of_philosophers can't be null");
	if (pthread_mutex_init(&ctx->mis_running, NULL))
		error(ctx, "Mutex init error");
}

static void	_philo_init_philos(t_philo_ctx *ctx)
{
	size_t	k;

	k = 0;
	while (k < ctx->nb)
	{
		ctx->philos[k].r_fork = &ctx->forks[(k + 1) % ctx->nb];
		ctx->philos[k].l_fork = &ctx->forks[k];
		ctx->philos[k].id = k;
		ctx->philos[k].last_eat = 0;
		ctx->philos[k].nb_ate = 0;
		ctx->philos[k].ctx = ctx;
		ctx->philos[k].thread_id = 0;
		if (pthread_mutex_init(&ctx->philos[k].eating, NULL)
			|| pthread_mutex_init(&ctx->philos[k].eaten, NULL))
			error(ctx, "Mutex init error");
		ctx->philos[k++].dead = 0;
	}
}

static void	_philo_init_forks(t_philo_ctx *ctx)
{
	size_t	k;

	k = 0;
	while (k < ctx->nb)
		if (pthread_mutex_init(&ctx->forks[k++], NULL))
			break ;
	if (k != ctx->nb)
		while (k-- != 0)
			pthread_mutex_destroy(&ctx->forks[k]);
}

void	philo_init(t_philo_ctx *ctx)
{
	ctx->forks = malloc(sizeof(*ctx->forks) * ctx->nb);
	if (ctx->forks == NULL)
		error(ctx, "Bad alloc");
	_philo_init_forks(ctx);
	ctx->philos = malloc(sizeof(*ctx->philos) * ctx->nb);
	if (ctx->philos == NULL)
		error(ctx, "Bad alloc");
	_philo_init_philos(ctx);
}
