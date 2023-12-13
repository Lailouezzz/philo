/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-boud <ale-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 12:21:18 by ale-boud          #+#    #+#             */
/*   Updated: 2023/12/13 22:11:42 by ale-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <stdnoreturn.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>

# define ERR_BAD_ALLOC 1

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

typedef struct s_philo
{
	pthread_t		thread_id;
	int				id;
	int				dead;
	unsigned int	nb_ate;
	void			*ctx;
	time_t			last_eat;
	pthread_mutex_t	eating;
	pthread_mutex_t	eaten;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*r_fork;
}				t_philo;

typedef struct s_philo_ctx
{
	char			*pn;
	unsigned int	nb;
	int				is_running;
	pthread_mutex_t	mis_running;
	time_t			t_todie;
	time_t			t_toeat;
	time_t			t_tosleep;
	unsigned int	t_toeach;
	t_philo			*philos;
	pthread_mutex_t	*forks;
}				t_philo_ctx;

/* PHILO */

void			philo_init_args(t_philo_ctx *ctx, int argc, char **argv);
void			philo_init(t_philo_ctx *ctx);
void			philo_start(t_philo_ctx *ctx);
void			philo_destroy(t_philo_ctx *ctx);

void			*philo_life(void *p);
void			philo_eat(t_philo *philo);
int				philo_is_running(t_philo_ctx *ctx);
void			philo_set_running(t_philo_ctx *ctx, int run);

noreturn void	error(t_philo_ctx *ctx, const char *s);

void			custom_sleep(t_philo *philo, time_t duration);

/* LOG */

typedef enum e_log_type
{
	LOG_FORK_TAKEN,
	LOG_EATING,
	LOG_SLEEPING,
	LOG_THINKING,
	LOG_DIED
}				t_log_type;

void			philo_log(t_philo_ctx *ctx, int nb, t_log_type type);

/* UTILS */

time_t			ft_time_ms(void);
void			ft_putstr_fd(int fd, const char *s);
int				ft_strlen(const char *s);
int				ft_atot(const char *s, time_t *t);
int				ft_atoui(const char *s, unsigned int *n);

#endif
