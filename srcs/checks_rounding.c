/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks_rounding.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrogg <mbrogg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 01:23:29 by kprmk             #+#    #+#             */
/*   Updated: 2020/02/21 00:01:44 by mbrogg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		is_half(char *str, int c)
{
	int len;

	len = ft_strlen(str);
	while (++c < len)
		if (str[c] != '0')
			return (0);
	return (1);
}

int		precision_in_da_house(t_lanch *res, int prec)
{
	int	hlf;

	hlf = 0;
	ft_strrev(&res->num);
	printf("\n^");
	for (int i = 0; i < res->len; i++)
		printf("%d ", res->num[i]);
	printf("\n");
	if (res->num[prec] > 5 || (res->num[prec] == 5 && (hlf = is_half(res->num, prec)) != 1))
		return (increas_lanch_one(res, prec));
	else if (hlf == 1 && res->num[prec - 1] % 2 == 1)
		return (increas_lanch_one(res, prec));
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
