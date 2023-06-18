/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armgevor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 18:32:19 by armgevor          #+#    #+#             */
/*   Updated: 2023/06/07 18:33:18 by armgevor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	stacar(int signal)
{
	if (signal == SIGUSR2)
		ft_printf("staca");
}

static int	ft_atoi(char *str)
{
	int	nshan;
	int	tiv;
	int	i;

	nshan = 1;
	tiv = 0;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			nshan = -1;
	while (str[i] >= 48 && str[i] <= 57)
		tiv = tiv * 10 + str[i++] - 48;
	return (nshan * tiv);
}

void	uxarkox(int pid, char c)
{
	int	bit;

	bit = -1;
	while (++bit < 8)
	{
		if (c & (1 << bit))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(100);
	}
}

int	main(int c, char **v)
{
	int	pid;
	int	i;

	if (c != 3)
	{
		ft_printf("sxal ka");
		return (0);
	}
	pid = ft_atoi(v[1]);
	i = -1;
	while (v[2][++i])
		uxarkox(pid, v[2][i]);
	signal(SIGUSR2, stacar);
	uxarkox(pid, '\0');
	return (0);
}
