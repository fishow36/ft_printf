/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_arithm_char_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrogg <mbrogg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 16:46:47 by mbrogg            #+#    #+#             */
/*   Updated: 2020/02/22 00:51:01 by mbrogg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		increas_lanch_one(t_lanch *res, int c)
{
	int remainder;
	int i;

	remainder = 0;
	i = c;
	while (c < res->len)
	{
		res->num[c] += remainder + ((c == i) ? 1 : 0);
		remainder = (res->num[c] > 9) ? 1 : 0;
		if (remainder == 1)
		{
			res->num[c] -= 10;
			if (c == res->len - 1)
				return (2);
		}
		c++;
	}
	return (0);
}

/*
**  WIDTH == -1 -> len = 3
**  WIDTH != -1 -> len = WIDTH
*/

t_lanch	*create_lanch(t_lanch *res, int width)
{
	int c;

	c = 0;
	if ((res = (t_lanch *)malloc(sizeof(t_lanch))) == NULL)
		exit(1);
	res->len = (width == -1) ? 3 : width;
	if ((res->num = (char *)malloc(sizeof(char) * (res->len + 1))) == NULL)
		exit(1);
	while (c < (int)res->len)
		res->num[c++] = 0;
	res->num[c] = '\0';
	return (res);
}

t_lanch	*cpy_lanch(t_lanch **src, int dst_len)
{
	int		count;
	t_lanch	*dst;

	count = 0;
	if ((dst = (t_lanch *)malloc(sizeof(t_lanch) * 1)) == NULL)
		exit(1);
	if ((dst->num = (char *)malloc(sizeof(char) * (dst_len + 1))) == NULL)
		exit(1);
	dst->len = dst_len;
	while (count < (*src)->len)
	{
		dst->num[count] = (*src)->num[count];
		count++;
	}
	while (count < dst_len)
		dst->num[count++] = 0;
	dst->num[count] = '\0';
	free((*src)->num);
	free(*src);
	return (dst);
}

t_lanch	*sum_lanch_nums_init(t_lanch *f, t_lanch *s)
{
	int		max;
	int		c;
	t_lanch	*res;

	max = f->len > s->len ? f->len : s->len;
	if ((res = (t_lanch *)malloc(sizeof(t_lanch))) == NULL)
		exit(1);
	if ((res->num = (char *)malloc(sizeof(char) * max)) == NULL)
		exit(1);
	c = -1;
	while (++c < max)
		res->num[c] = 0;
	res->len = max;
	return (res);
}
