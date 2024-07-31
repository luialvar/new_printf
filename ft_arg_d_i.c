/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arg_d_i.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luialvar <luialvar@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 12:58:54 by luialvar          #+#    #+#             */
/*   Updated: 2024/07/29 14:56:14 by luialvar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_int_counter(int num)
{
	int		i;
	long	n;

	n = num;
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

int	ft_arg_d_i(int num)
{
	ft_putnbr_fd(num, 1);
	return (ft_int_counter(num));
}
