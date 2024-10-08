/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arg_p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luialvar <luialvar@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 11:27:16 by luialvar          #+#    #+#             */
/*   Updated: 2024/07/31 11:39:44 by luialvar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_hex_len(unsigned long nbr)
{
	int	len;

	len = 0;
	while (nbr > 0)
	{
		nbr /= 16;
		len++;
	}
	return (len);
}

static char	ft_decimal_to_hex(char digit, char type)
{
	int	caps;

	caps = 0;
	if (type == 'X')
		caps = 32;
	if (digit > 9)
	{
		if (digit == 10)
			return ('a' - caps);
		if (digit == 11)
			return ('b' - caps);
		if (digit == 12)
			return ('c' - caps);
		if (digit == 13)
			return ('d' - caps);
		if (digit == 14)
			return ('e' - caps);
		if (digit == 15)
			return ('f' - caps);
	}
	else
		return (digit + '0');
	return (0);
}

static int	ft_reverse_str(char *str)
{
	int	i;
	int	bytes;

	bytes = ft_strlen(str);
	i = bytes - 1;
	while (i >= 0)
	{
		write(1, &str[i], sizeof(char) * 1);
		i--;
	}
	return (bytes);
}

int	ft_arg_p(unsigned long address)
{
	char	*num;
	int		bytes;
	int		i;

	i = 0;
	if (!address)
		return (write(1, "0x0", sizeof(char) * 3));
	bytes = write(1, "0x", sizeof(char) * 2);
	num = (char *)malloc(((ft_hex_len(address)) + 1) * sizeof(char));
	while (address)
	{
		num[i] = ft_decimal_to_hex(address % 16, 'x');
		address /= 16;
		i++;
	}
	num[i] = '\0';
	bytes += ft_reverse_str(num);
	free(num);
	num = NULL;
	return (bytes);
}
