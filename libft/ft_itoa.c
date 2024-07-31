/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luialvar <luialvar@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 12:04:18 by luialvar          #+#    #+#             */
/*   Updated: 2024/04/11 12:08:47 by luialvar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_int_counter(int n)
{
	int	count;

	count = 0;
	if (n <= 0)
		count = 1;
	while (n != 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

static long int	ft_abs(long int n)
{
	if (n < 0)
		n = -n;
	return (n);
}

char	*ft_itoa(int n)
{
	long int	num;
	int			length;
	char		*str;

	num = n;
	length = ft_int_counter(n);
	str = (char *)malloc(sizeof(char) * (length + 1));
	if (str == NULL)
		return (NULL);
	str[length] = '\0';
	if (n == 0)
		str[0] = '0';
	num = ft_abs(num);
	while (length > 0)
	{
		length--;
		str[length] = (num % 10) + '0';
		num = num / 10;
		if (num == 0 && n >= 0)
			return (str);
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}
