/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks_rounding.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrogg <mbrogg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 01:23:29 by kprmk             #+#    #+#             */
/*   Updated: 2020/02/22 00:17:06 by mbrogg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_str_is_null_value(char *str)
{
	int c;
	int len;

	len = ft_strlen(str);
	c = 0;
	while (c < len)
		if (str[c++] != '0')
			return (1);
	return (0);
}

int		is_half(char *str, int c)
{
	while (--c >= 0)
		if (str[c] != 0)
			return (0);
	return (1);
}

int		precision_in_da_house(t_lanch *res, int prec)
{
	int	hlf;
	int	index;

	hlf = 0;
	index = prec > res->len ? 0 : res->len - prec - 1;
	hlf = is_half(res->num, index);
	if (res->num[index] >= 5 && hlf == 0 && prec == 0)
		return (2);
	else if (hlf == 1 && prec == 0)
		return (1);
	else if (res->num[index] > 5 || (res->num[index] == 5 && hlf != 1))
		return (increas_lanch_one(res, index + 1));
	else if (hlf == 1 && res->num[index + 1] % 2 == 1)
		return (increas_lanch_one(res, index + 1));
	else
		return (0);
}

int		check_inf_nan(t_ldbl res)
{
	if (res.parts.exp & (0x7ffff == 0x7ffff))
	{
		if (res.parts.mant & (0xffffffffffffffff == 0x8000000000000000))
		{
			if (res.parts.sign == 0)
				ft_putstr("+inf");
			else
				ft_putstr("-inf");
		}
		return (-1);
	}
	return (1);
}
