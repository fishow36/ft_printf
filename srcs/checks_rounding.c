/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks_rounding.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshor <eshor@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 01:23:29 by kprmk             #+#    #+#             */
/*   Updated: 2020/02/20 19:54:31 by eshor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		is_half(int c)
{
	while (--c >= 0)
		if (c != 0)
			return (0);
	return (1);
}

int		precision_in_da_house(t_lanch *res, int prec)
{
	int c;
	int	hlf;

	hlf = 0;
	c = res->len - prec - 1;
	if (res->num[c] > 5 || (res->num[c] == 5 && (hlf = is_half(c)) != 1))
		return (increas_lanch_one(res, c + 1));
	else if (hlf == 1 && res->num[res->len - prec] % 2 == 1)
		return (increas_lanch_one(res, c + 1));
	else if (hlf == 1 && prec == 0)
		return (1);
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
