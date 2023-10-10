/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-boud <ale-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 12:21:18 by ale-boud          #+#    #+#             */
/*   Updated: 2023/10/10 10:52:54 by ale-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <stdnoreturn.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>

typedef enum e_args
{
	PROG_NAME,
	PROG_NBPHILO,
	PROG_TTODIE,
	PROG_TTOEAT,
	PROG_TTOSLEEP,
	PROG_TTOEACHP,
	PROG__MIN=PROG_TTOSLEEP + 1,
	PROG__MAX=PROG_TTOEACHP + 1,
}				t_args;

typedef struct s_philoctx
{
	char			*pn;
	int				nb;
	time_t			ttodie;
	time_t			ttoeat;
	time_t			ttosleep;
	int				ttoeach;
	pthread_mutex_t	*write;
}				t_philoctx;

/* PHILO */

void			philo_init(t_philoctx *ctx, int argc, char **argv);

noreturn void	error(t_philoctx *ctx, const char *s);

/* LOG */


/* UTILS */

time_t			ft_timems(void);
void			ft_putstr_fd(int fd, const char *s);
int				ft_strlen(const char *s);
int				ft_atot(const char *s, time_t *t);
int				ft_atoui(const char *s, int *n);

#endif
