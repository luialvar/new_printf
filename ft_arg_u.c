/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arg_u.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luialvar <luialvar@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 13:37:29 by luialvar          #+#    #+#             */
/*   Updated: 2024/07/30 12:17:43 by luialvar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// Función para contar el número de dígitos en un número sin signo
static int	ft_unsigned_counter(unsigned int n)
{
	int	i;

	i = 1;
	while ((n / 10) >= 1)
	{
		i++;
		n = n / 10;
	}
	return (i);
}
// Función para imprimir un número sin signo (unsigned int) en el file 
//descriptor dado sin recursividad

static void	ft_putnbr_unsigned_fd(unsigned int n, int fd)
{
	unsigned int	divisor;
	unsigned int	num_digits;
	unsigned int	i;
	unsigned int	digit;

	divisor = 1;
	num_digits = ft_unsigned_counter(n);
	i = 1;
	while (i < num_digits)
	{
		divisor *= 10;
		i++;
	}
	while (divisor > 0)
	{
		digit = n / divisor;
		ft_putchar_fd(digit + '0', fd);
		n %= divisor;
		divisor /= 10;
	}
}

int	ft_arg_u(unsigned int num)
{
	ft_putnbr_unsigned_fd(num, 1);
	return (ft_unsigned_counter(num));
}
