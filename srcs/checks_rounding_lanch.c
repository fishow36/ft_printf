/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision_lanch.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrogg <mbrogg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 01:23:29 by kprmk             #+#    #+#             */
/*   Updated: 2020/02/20 16:28:19 by mbrogg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		increas_lanch_one(t_lanch *res, int c)
{
	int remainder;
	int i;
	
	remainder = 0;
	i = c;
	if (c == res->len)
		return (1);
	while (c < res->len)
	{
		res->num[c] += remainder + ((c == i) ? 1 : 0);
		remainder = (res->num[c] > 9) ? 1 : 0;
		if (remainder == 1)
		{
			res->num[c] -= 10;
			if (c == res->len - 1)
				return (1);
		}
		c++;
	}
	return (0);
}

int		is_half(t_lanch *res, int c)
{
	while(--c >= 0)
		if (c != 0)
			return (0);
	return (1);
}

int		precision_in_da_house(t_lanch *res, int prec)
{
	int c;
	int	hlf;

	c = res->len - prec - 1;
	if (res->num[c] > 5 || (res->num[c] == 5 && (hlf = is_half(res, c)) != 1))
		return (increas_lanch_one(res, c + 1));
	else if (hlf == 1 && res->num[res->len - prec] % 2 == 1)
		return (increas_lanch_one(res, c + 1));
	else if (hlf == 1 && prec == 0)
		return (1);
	else
		return (0);
}

/*
**  WIDTH == -1 -> len = 3
**  WIDTH != -1 -> len = WIDTH
*/

int		create_lanch(t_lanch *res, int width)
{
	int c;

	c = 0;
	res->len = (width == -1) ? 3 : width;
	res->num = (char *)malloc(sizeof(char) * (res->len + 1));
	if (res->num == NULL)
		return (-1);
	while (c < (int)res->len)
		res->num[c++] = 0;
	res->num[c] = '\0';
	return (1);
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
