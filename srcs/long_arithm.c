/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_arithm.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrogg <mbrogg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 11:46:34 by mbrogg            #+#    #+#             */
/*   Updated: 2020/02/20 17:51:12 by mbrogg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_lan	create_lan_from_bitstr(char *str)
{
	t_lan	res;
	t_lan	temp;
	int		c;
	int		len_str;

	len_str = ft_strlen(str);
	if ((res.num = (int *)malloc(sizeof(int) * 1)) == NULL)
		exit(1);
	res.num[0] = 0;
	res.len = 1;
	c = 0;
	while (len_str - c > 0)
	{
		if (str[len_str - c - 1] == '1')
		{
			temp = power_of_two_lan(c);
			res = sum_lan_nums(res, temp);
		}
		c++;
	}
	return (res);
}

t_lan	power_of_two_lan(int num)
{
	t_lan	temp;

	temp.len = 1;
	temp.num = (int *)malloc(sizeof(int) * (temp.len));
	temp.num[0] = 1;
	while (num-- > 0)
		temp = sum_lan_nums(temp, temp);
	return (temp);
}

void	change_lan_rank(t_lan *p_lan)
{
	int	*temp;
	int	c;

	c = -1;
	temp = (int *)malloc(sizeof(int) * (p_lan->len));
	while (++c < (int)p_lan->len)
		temp[c] = p_lan->num[c];
	free(p_lan->num);
	p_lan->len++;
	p_lan->num = (int *)malloc(sizeof(int) * (p_lan->len));
	c = -1;
	while (++c < (int)p_lan->len - 1)
		p_lan->num[c] = temp[c];
	p_lan->num[c] = 0;
}

t_lan	sum_lan_nums(t_lan f, t_lan s)
{
	int		remainder;
	size_t	c;
	size_t	max;

	remainder = 0;
	c = 0;
	max = f.len > s.len ? f.len : s.len;
	while (c < max || remainder > 0)
	{
		if (c == f.len)
			change_lan_rank(&f);
		f.num[c] += remainder + (c < s.len ? s.num[c] : 0);
		remainder = (f.num[c] > 9999) ? 1 : 0;
		if (remainder == 1)
			f.num[c] -= 10000;
		c++;
	}
	return (f);
}
