/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-boud <ale-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 12:46:44 by ale-boud          #+#    #+#             */
/*   Updated: 2023/10/10 10:53:04 by ale-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

noreturn void	help(char **argv)
{
	ft_putstr_fd(STDOUT_FILENO, "Usage: ");
	ft_putstr_fd(STDOUT_FILENO, argv[PROG_NAME]);
	ft_putstr_fd(STDOUT_FILENO, " number_of_philosophers time_to_die time_to_eat \
time_to_sleep [number_of_times_each_philosopher_must_eat]\n");
	exit(EXIT_SUCCESS);
}

int	main(int argc, char **argv)
{
	t_philoctx	ctx;

	if (argc < PROG__MIN || argc > PROG__MAX)
		help(argv);
	philo_init(&ctx, argc, argv);
	return (EXIT_SUCCESS);
}
