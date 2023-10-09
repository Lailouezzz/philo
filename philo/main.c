/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-boud <ale-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 12:46:44 by ale-boud          #+#    #+#             */
/*   Updated: 2023/10/09 13:54:49 by ale-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

typedef enum e_args
{
	PROG_NAME,
	PROG_NBPHILO,
	PROG_TTODIE,
	PROG_TTOEAT,
	PROG_TTOSLEEP,
	PROG_TTOEACHP,
	PROG__MIN=PROG_TTOSLEEP,
	PROG__MAX=PROG_TTOEACHP,
}	t_args;

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
	if (argc < PROG__MIN || argc > PROG__MAX)
		help(argv);
	return (EXIT_SUCCESS);
}
