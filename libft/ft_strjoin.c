/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luialvar <luialvar@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 14:15:50 by luialvar          #+#    #+#             */
/*   Updated: 2024/02/12 14:27:45 by luialvar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*retorno;
	size_t	size;

	if (!s1 || !s2)
		return (0);
	size = ft_strlen(s1) + ft_strlen(s2);
	retorno = (char *)malloc(size + 1);
	if (!retorno)
		return (0);
	ft_memcpy(retorno, s1, ft_strlen(s1));
	ft_memcpy(retorno + ft_strlen(s1), s2, ft_strlen(s2));
	retorno[size] = '\0';
	return (retorno);
}
