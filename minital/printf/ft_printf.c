/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armgevor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 21:12:42 by armgevor          #+#    #+#             */
/*   Updated: 2023/06/07 18:16:44 by armgevor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//%c
int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

//%s
int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (!s)
		s = "(null)";
	while (s[i])
	{
		ft_putchar(s[i]);
		i++;
	}
	return (i);
}

//%X
int	ft_puthexx(unsigned int tiv)
{
	unsigned long long	ptr;
	int					count;

	ptr = (unsigned long long)tiv;
	count = 0;
	if (ptr > 15)
		count = ft_puthexx(ptr / 16);
	count++;
	ft_putchar("0123456789ABCDEF"[ptr % 16]);
	return (count);
}

int	stugum(char nish, va_list arg_list)
{
	int	canak;

	canak = 0;
	if (nish == 'c')
		canak = ft_putchar(va_arg(arg_list, int));
	else if (nish == 's')
		canak = ft_putstr(va_arg(arg_list, char *));
	else if (nish == 'x')
		canak = ft_puthex(va_arg(arg_list, unsigned int));
	else if (nish == 'X')
		canak = ft_puthexx(va_arg(arg_list, unsigned int));
	else if (nish == 'd' || nish == 'i')
		canak = ft_putnbr(va_arg(arg_list, int));
	else if (nish == 'p')
		canak = ft_putptr(va_arg(arg_list, void *));
	else if (nish == 'u')
		canak = ft_putnbru(va_arg(arg_list, unsigned int));
	else if (nish == '%')
		canak = ft_putchar('%');
	else
		canak = ft_putchar (nish);
	return (canak);
}

int	ft_printf(const char *tokos, ...)
{
	int		n;
	int		i;
	va_list	rest;

	i = -1;
	n = 0;
	va_start(rest, tokos);
	while (tokos[++i])
	{
		if (tokos[i] == '%' && !tokos[i + 1])
			break ;
		if (tokos[i] == '%' && tokos[i + 1])
			n += stugum(tokos[++i], rest);
		else
			n += write(1, &tokos[i], 1);
	}
	va_end(rest);
	return (n);
}
