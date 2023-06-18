/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armgevor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 08:43:35 by armgevor          #+#    #+#             */
/*   Updated: 2023/02/19 17:42:52 by armgevor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

int	ft_puthexx(unsigned int tiv);
int	ft_puthex(unsigned int tiv);
int	ft_putptr(void *p);
int	ft_putnbru(unsigned int n);
int	ft_putnbr(int nb);
int	ft_putstr(char *s);
int	ft_putchar(char c);
int	ft_ft(unsigned long long n);
int	stugum(char syb, va_list arg_list);
int	ft_printf(const char *placeholder, ...);

#endif
