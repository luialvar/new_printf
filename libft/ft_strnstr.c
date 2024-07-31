/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luialvar <luialvar@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 11:22:20 by luialvar          #+#    #+#             */
/*   Updated: 2024/02/03 14:54:01 by luialvar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	nlen;

	if (*little == 0)
		return ((char *) big);
	i = 0;
	nlen = ft_strlen(little);
	while (i < len && big[i])
	{
		if (big[i] == *little && len - i >= nlen
			&& ft_strncmp(&big[i], little, nlen) == 0)
			return ((char *) &big[i]);
		i++;
	}
	return (NULL);
}
