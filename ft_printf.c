/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luialvar <luialvar@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 13:13:27 by luialvar          #+#    #+#             */
/*   Updated: 2024/07/31 12:09:47 by luialvar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_checker(va_list vargs, char c)
{
	int	n_bytes;

	n_bytes = 0;
	if (c == 'c')
		n_bytes += ft_arg_c(va_arg(vargs, int));
	if (c == 's')
		n_bytes += ft_arg_s(va_arg(vargs, char *));
	if (c == 'p')
		n_bytes += ft_arg_p(va_arg(vargs, unsigned long));
	if (c == 'd' || c == 'i')
		n_bytes += ft_arg_d_i(va_arg(vargs, int));
	if (c == 'u')
		n_bytes += ft_arg_u(va_arg(vargs, unsigned int));
	if (c == 'X' || c == 'x')
		n_bytes += ft_arg_x_X(va_arg(vargs, unsigned int), c);
	if (c == '%')
		n_bytes += ft_arg_perc();
	return (n_bytes);
}
//la función va_arg es la clave porque es como una lista de los elementos que 
//se pasan al printf, y cada vez que se llama pasa al siguiente

int	ft_printf(char const *str, ...)
{
	va_list	vargs;
	int		i;
	int		n_bytes;

	va_start (vargs, str);
	i = 0;
	n_bytes = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			n_bytes += ft_checker(vargs, str[i + 1]);
			i++;
		}
		else
		{
			n_bytes += write(1, &str[i], sizeof(char));
		}
		i++;
	}
	va_end(vargs);
	return (n_bytes);
}
