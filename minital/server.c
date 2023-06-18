/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armgevor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 18:30:42 by armgevor          #+#    #+#             */
/*   Updated: 2023/06/07 18:31:02 by armgevor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	stacox(int signal)
{
	static int	bit;
	static int	c;

	if (signal == SIGUSR1)
		c |= (1 << bit);
	bit++;
	if (bit == 8)
	{
		ft_printf("%c", c);
		bit = 0;
		c = 0;
	}
}

int	main(int c, char **v)
{
	int	pid;

	(void)v;
	if (c != 1)
	{
		ft_printf("sxal ka");
		return (0);
	}
	pid = getpid();
	ft_printf("%d\n", pid);
	signal(SIGUSR1, stacox);
	signal(SIGUSR2, stacox);
	while (1)
		pause();
	return (0);
}
