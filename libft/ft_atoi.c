/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luialvar <luialvar@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 13:21:03 by luialvar          #+#    #+#             */
/*   Updated: 2024/02/10 16:49:48 by luialvar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	i;
	int	sign;
	int	num;

	i = 0;
	sign = 1;
	num = 0;
	while (nptr[i] == ' ' || (nptr[i] > 8 && nptr[i] < 14))
		i++;
	if (nptr[i] == '-')
		sign *= -1;
	if (nptr[i] == '+' || nptr[i] == '-')
		i++;
	if (nptr[i] < '0' || nptr[i] > '9')
	{
		return (0);
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		num = (nptr[i] - 48) + (num * 10);
		i++;
	}
	return (num * sign);
}

/*
int main()
{
	int i = ft_atoi ("+234");
	printf ("%d", i);
}*/
