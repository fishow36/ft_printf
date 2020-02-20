/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_arithm_char_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrogg <mbrogg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 16:46:47 by mbrogg            #+#    #+#             */
/*   Updated: 2020/02/20 16:51:25 by mbrogg           ###   ########.fr       */
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

int		cpy_lanch_str(t_lanch *dst, t_lanch *src)
{
	size_t	count;

	count = 0;
	if ((dst->num = (char *)malloc(sizeof(char) * (dst->len + 1))) == NULL)
		return (-1);
	while (count < src->len)
	{
		dst->num[count] = src->num[count];
		count++;
	}
	while (count < dst->len)
		dst->num[count++] = 0;
	dst->num[count] = '\0';
	return (1);
}
