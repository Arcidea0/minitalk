/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armgevor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 20:16:21 by armgevor          #+#    #+#             */
/*   Updated: 2023/02/21 21:26:11 by armgevor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//%d && %i
int	ft_putnbr(int nb)
{
	unsigned int	nbr;
	int				i;
	int				nshan;

	i = 0;
	nshan = 0;
	if (nb < 0)
	{
		nshan = ft_putchar('-');
		nbr = (unsigned int)(nb * -1);
	}
	else
		nbr = (unsigned int)nb;
	if (nbr >= 10)
		i = ft_putnbr(nbr / 10);
	i++;
	ft_putchar((char)(nbr % 10 + 48));
	return (i + nshan);
}

//%u
int	ft_putnbru(unsigned int n)
{
	int	i;

	i = 0;
	if (n >= 10)
		i = ft_putnbr(n / 10);
	i++;
	ft_putchar((char)(n % 10 + 48));
	return (i);
}

//%p
int	ft_putptr(void *p)
{
	int					count;
	unsigned long long	ptr;

	ptr = (unsigned long long)p;
	count = 0;
	count += write(1, "0x", 2);
	count += ft_ft(ptr);
	return (count);
}

//p
int	ft_ft(unsigned long long ptr)
{
	int	count;

	count = 0;
	if (ptr > 15)
		count = ft_ft(ptr / 16);
	count++;
	ft_putchar("0123456789abcdef"[ptr % 16]);
	return (count);
}

//%x
int	ft_puthex(unsigned int tiv)
{
	unsigned long long	ptr;
	int					count;

	ptr = (unsigned long long)tiv;
	count = 0;
	if (ptr > 15)
		count = ft_puthex(ptr / 16);
	count++;
	ft_putchar("0123456789abcdef"[ptr % 16]);
	return (count);
}
