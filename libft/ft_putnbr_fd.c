/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luialvar <luialvar@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 14:25:11 by luialvar          #+#    #+#             */
/*   Updated: 2024/02/14 12:08:33 by luialvar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long int	ft_int_counter(long int n)
{
	int	i;

	i = 1;
	if (n < 0)
	{
		n *= -1;
	}
	while ((n / 10) >= 1)
	{
		i++;
		n = n / 10;
	}
	return (i);
}

static long int	new_number(long int num, int contador)
{
	long int	resultado;
	long int	variable;

	resultado = 0;
	variable = 1;
	while (contador > 1)
	{
		resultado += (num % 10) * (variable);
		num = num / 10;
		variable *= 10;
		contador--;
	}
	return (resultado);
}

void	ft_putnbr_fd(int n, int fd)
{
	long int	num;
	long int	num_const;
	long int	contador;
	long int	contador_const;

	num_const = n;
	if (num_const < 0)
	{
		ft_putchar_fd('-', fd);
		num_const *= -1;
	}
	contador_const = ft_int_counter (num_const);
	while (contador_const > 0)
	{
		num = num_const;
		contador = contador_const;
		while (contador > 1)
		{
			num = num / 10;
			contador--;
		}
		ft_putchar_fd(num + 48, fd);
		num_const = new_number (num_const, contador_const);
		contador_const--;
	}
}
/*
int	main(void)
{
    int	num = -63279;
    ft_putnbr_fd(num, 1);
    return (0);
}
*/
