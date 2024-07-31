/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arg_s.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luialvar <luialvar@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 12:54:08 by luialvar          #+#    #+#             */
/*   Updated: 2024/07/21 12:55:54 by luialvar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_arg_s(char *str)
{
	if (!str)
		return (write(1, "(null)", sizeof(char) * 6));
	ft_putstr_fd(str, 1);
	return (ft_strlen(str));
}
