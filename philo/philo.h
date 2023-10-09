/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-boud <ale-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 12:21:18 by ale-boud          #+#    #+#             */
/*   Updated: 2023/10/09 13:50:15 by ale-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <stdnoreturn.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>

typedef struct s_logctx
{
	pthread_mutex_t	write;
}	t_logctx;

typedef struct s_philoctx
{
	int			nb;
	time_t		ttodie;
	time_t		ttoeat;
	time_t		ttosleep;
	int			ttoeach;
	t_logctx	*logctx;
}	t_philoctx;

/* LOG */



/* UTILS */

time_t	ft_timems(void);
void	ft_putstr_fd(int fd, const char *s);
int		ft_strlen(const char *s);

#endif
