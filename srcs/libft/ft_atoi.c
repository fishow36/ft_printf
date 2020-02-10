/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrogg <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 19:51:59 by mbrogg            #+#    #+#             */
/*   Updated: 2019/09/14 19:56:08 by mbrogg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	char			*s;
	unsigned long	res;
	unsigned long	war;
	size_t			sign;

	sign = 0;
	s = (char *)str;
	res = 0;
	war = (~res / 2) / 10;
	s = ft_spaces(s);
	sign = (*s == '-' ? 1 : 2);
	if (*s == '+' || *s == '-')
		s++;
	while (ft_isdigit(*s))
	{
		if (sign != 1 && (war < res || (war == res && *str - '0' > 7)))
			return (-1);
		else if (sign == 1 && (war < res || (war == res && *str - '0' > 8)))
			return (0);
		res = res * 10 + *s++ - '0';
	}
	res *= (sign == 1 ? -1 : 1);
	return ((int)res);
}
