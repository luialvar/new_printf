/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luialvar <luialvar@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 11:10:25 by luialvar          #+#    #+#             */
/*   Updated: 2024/04/12 11:21:13 by luialvar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_num_palabras(char const *s, char c)
{
	int	num;

	num = 0;
	while (*s)
	{
		if (*s != c)
		{
			num++;
			while (*s && *s != c)
				s++;
		}
		else
			s++;
	}
	return (num);
}

static void	ft_free(char **str, int str_ind)
{
	while (str_ind > 0)
	{
		str_ind--;
		free(str[str_ind]);
	}
	free(str);
}

static int	ft_wordsize(char const *s, char c, int i)
{
	int	len;

	len = 0;
	while (s[i] && s[i] != c)
	{
		len++;
		i++;
	}
	return (len);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	int		i;
	int		str_ind;

	i = 0;
	str_ind = -1;
	str = malloc(sizeof(char *) * (ft_num_palabras (s, c) + 1));
	if (!str)
		return (NULL);
	while (++str_ind < ft_num_palabras (s, c))
	{
		while (s[i] == c)
			i++;
		str[str_ind] = ft_substr(s, i, ft_wordsize(s, c, i));
		if (!(str[str_ind]))
		{
			ft_free(str, str_ind);
			return (NULL);
		}
		i += ft_wordsize(s, c, i);
	}
	str[str_ind] = NULL;
	return (str);
}
