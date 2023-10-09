/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-boud <ale-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 12:53:55 by ale-boud          #+#    #+#             */
/*   Updated: 2023/10/09 13:17:47 by ale-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

time_t	ft_timems(void)
{
	static time_t	initime = -1;
	struct timeval	t;

	gettimeofday(&t, NULL);
	if (initime == -1)
		initime = (t.tv_sec * 1000 + t.tv_usec / 1000);
	return ((t.tv_sec * 1000 + t.tv_usec / 1000) - initime);
}

void	ft_putstr_fd(int fd, const char *s)
{
	write(fd, s, ft_strlen(s));
}

int	ft_strlen(const char *s)
{
	int	k;

	k = 0;
	while (s[k] != '\0')
		++k;
	return (k);
}
