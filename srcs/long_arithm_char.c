/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_arithm_char.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrogg <mbrogg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 11:46:34 by mbrogg            #+#    #+#             */
/*   Updated: 2020/02/21 23:23:56 by mbrogg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**  type == -1 -> rank += 1
*/

t_lanch	*change_lanch_rank(t_lanch **p_lan, int type)
{
	t_lanch	*temp;
	int		new_len;

	new_len = (type == -1) ? (*p_lan)->len + 1 : type;
	temp = cpy_lanch(p_lan, new_len);
	return (temp);
}

void	power_of_five_lanch_inside(t_lanch **temp, int *c, int *r)
{
	if (*c == (int)(*temp)->len)
	{
		*temp = change_lanch_rank(temp, -1);
	}
	(*temp)->num[*c] = (*temp)->num[*c] * 5 + *r;
	*r = ((*temp)->num[*c] > 9) ? (*temp)->num[*c] / 10 : 0;
	if (*r != 0)
		(*temp)->num[*c] %= 10;
	(*c)++;
}

t_lanch	*power_of_five_lanch(int num, int width)
{
	t_lanch	*temp;
	int		remainder;
	int		c;
	int		cp;

	cp = num;
	remainder = 0;
	temp = create_lanch(temp, width);
	if (width == -1)
		temp->num[0] = 1;
	else
		temp->num[width - num] = 1;
	while (cp-- > 0)
	{
		c = (width == -1) ? 0 : width - num;
		while (c < (int)temp->len || remainder > 0)
			power_of_five_lanch_inside(&temp, &c, &remainder);
	}
	return (temp);
}

/*
**	TYPE
**	0 - > there are both parts
**	n - > there is only frac_part
*/

int		create_lanch_from_bitstr(t_lanch **res, char *str, int prec)
{
	int		c;
	int		len_str;
	int		length;
	t_lanch	*temp;

	len_str = ft_strlen(str);
	// *res = create_lanch(*res, -1);
	c = len_str - 1;
	while (c > 0 && str[c] == '0')
		c--;
	*res = power_of_five_lanch(c + 1, -1);
	*res = change_lanch_rank(res, c + 1);
	len_str = c;
	length = (*res)->len;
	c = -1;
	while (++c < len_str)
	{
		if (str[c] == '1')
			*res = sum_lanch_nums(*res, power_of_five_lanch(c + 1, length));
	}
	c = precision_in_da_house(*res, prec);
	return (c);
}

/*
**  f - first, s - second
*/

t_lanch	*sum_lanch_nums(t_lanch *f, t_lanch *s)
{
	int		remainder;
	size_t	c;
	size_t	max;
	t_lanch	*res;

	remainder = 0;
	c = 0;
	max = f->len > s->len ? f->len : s->len;
	if ((res = (t_lanch *)malloc(sizeof(t_lanch))) == NULL)
		exit(1);
	if ((res->num = (char *)malloc(sizeof(char) * max)) == NULL)
		exit(1);
	while (++c < max)
		res->num[c] = 0;
	res->len = max;
	c = 0;
	while (c < max || remainder > 0)
	{
		if (c == res->len)
			f = change_lanch_rank(&f, 1);
		res->num[c] = (c < f->len ? f->num[c] : 0) + remainder + (c < s->len ? s->num[c] : 0);
		remainder = (res->num[c] > 9) ? 1 : 0;
		if (remainder == 1)
			res->num[c] -= 10;
		c++;
	}
	free(s->num);
	free(s);
	free(f->num);
	free(f);
	return (res);
}
