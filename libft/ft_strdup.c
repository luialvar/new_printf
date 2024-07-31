/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luialvar <luialvar@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 15:12:18 by luialvar          #+#    #+#             */
/*   Updated: 2024/02/12 13:21:39 by luialvar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	len;
	size_t	i;
	char	*dinamic;

	len = ft_strlen(s1) + 1;
	i = 0;
	dinamic = ft_calloc (len, 1);
	if (!dinamic)
		return (NULL);
	while (i < len)
	{
		dinamic [i] = s1 [i];
		i++;
	}
	return (dinamic);
}
