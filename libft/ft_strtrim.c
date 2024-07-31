/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luialvar <luialvar@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 14:40:32 by luialvar          #+#    #+#             */
/*   Updated: 2024/02/12 15:32:19 by luialvar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(s1);
	if (!s1 || !set)
		return (0);
	if (s1[i] == '\0' && len == 0)
		return (ft_strdup(""));
	while (ft_strchr(set, s1[i]))
		i++;
	while (ft_strchr(set, s1[len]))
		len--;
	return (ft_substr(s1, i, len - i + 1));
}
