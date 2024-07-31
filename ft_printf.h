/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luialvar <luialvar@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 13:12:02 by luialvar          #+#    #+#             */
/*   Updated: 2024/07/31 10:42:12 by luialvar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include "libft.h"

int		ft_printf(const char *string, ...);
int		ft_arg_perc(void);
int		ft_arg_c(char c);
int		ft_arg_s(char *s);
int		ft_arg_u(unsigned int nbr);
int		ft_arg_d_i(int c);
int		ft_arg_p(unsigned long nbr);
int		ft_arg_x_X(unsigned int nbr, char type);

#endif
