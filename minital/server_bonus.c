/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armgevor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 18:31:10 by armgevor          #+#    #+#             */
/*   Updated: 2023/06/07 18:53:52 by armgevor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"
#include <sys/signal.h>

void	stacox(int signal, siginfo_t *info, void *cont)
{
	static int	bit;
	static int	c;

	(void)cont;
	if (signal == SIGUSR1)
		c |= (1 << bit);
	bit++;
	if (bit == 8)
	{
		if (c == 0)
			kill(info->si_pid, SIGUSR2);
		ft_printf("%c", c);
		bit = 0;
		c = 0;
	}
}

int	main(int c, char **v)
{
	int					pid;
	struct sigaction	act;

	(void)v;
	if (c != 1)
	{
		ft_printf("sxal ka");
		return (0);
	}
	pid = getpid();
	act.sa_flags = SA_RESTART;
	ft_printf("%d\n", pid);
	act.sa_sigaction = stacox;
	sigemptyset(&act.sa_mask);
	act.sa_flags = 0;
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
	while (1)
		pause();
	return (0);
}
