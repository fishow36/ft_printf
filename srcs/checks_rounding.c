/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks_rounding.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrogg <mbrogg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 01:23:29 by kprmk             #+#    #+#             */
/*   Updated: 2020/02/22 01:54:20 by mbrogg           ###   ########.fr       */
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
	if (prec >= res->len)
		return (0);
	index = res->len - prec - 1;
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

/*
**	2 -> nan
**	1 -> inf
**	-1 -> -inf
**	0 -> OK
**	TYPE == 1 -> ONES
**	TYPE == 0 -> ZEROS
*/

int		if_ones_zeros(unsigned num, int amount, int type)
{
	int	c;

	c = amount - 1;
	if (type == 1)
	{
		while ((c > -1) && ((num & (1 << c)) != 0))
			c--;
		if (c != -1)
			return (0);
		return (1);
	}
	else
	{
		while ((c > -1) && !((num & (1 << c)) != 0))
			c--;
		if (c != -1)
			return (0);
		return (1);
	}
}

int		check_inf_nan(t_ldbl *res)
{
	if (if_ones_zeros(res->parts.exp, 15, 1) == 1)
	{
		if (if_ones_zeros(res->parts.mant, 63, 0) == 1)
			return (res->parts.sign == 1 ? -1 : 1);
		return (2);
	}
	return (0);
}
