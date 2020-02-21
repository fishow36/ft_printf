/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_arithm.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrogg <mbrogg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 11:46:34 by mbrogg            #+#    #+#             */
/*   Updated: 2020/02/21 19:11:28 by mbrogg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_lan	*create_lan_from_bitstr(char *str)
{
	t_lan	*res;
	int		c;
	int		len_str;

	len_str = ft_strlen(str);
	if ((res = (t_lan *)malloc(sizeof(t_lan))) == NULL)
		exit(1);
	if ((res->num = (int *)malloc(sizeof(int) * 1)) == NULL)
		exit(1);
	res->num[0] = 0;
	res->len = 1;
	c = 0;
	while (len_str - c > 0)
	{
		if (str[len_str - c - 1] == '1')
		{
			res = sum_lan_nums(res, power_of_two_lan(c));
			// printf("!");
			// for (int i = 0; i < res->len; i++)
			// 	printf("%d ", res->num[i]);
			// printf("\n");
		}
		c++;
	}
	return (res);
}

t_lan	*power_of_two_lan(int num)
{
	t_lan	*temp;

	if ((temp = (t_lan *)malloc(sizeof(t_lan))) == NULL)
		exit(1);
	temp->len = 1;
	if ((temp->num = (int *)malloc(sizeof(int) * (temp->len))) == NULL)
		exit(1);
	temp->num[0] = 1;
	while (num-- > 0)
	{
		// for (int i = 0; i < temp->len; i++)
		// 	printf("%d ", temp->num[i]);
		// printf("\n");
		temp = sum_lan_nums(temp, temp);
	}
	return (temp);
}

void	change_lan_rank(t_lan **p_lan)
{
	int	*temp;
	int	c;

	c = -1;
	temp = (int *)malloc(sizeof(int) * ((*p_lan)->len));
	while (++c < (int)(*p_lan)->len)
		temp[c] = (*p_lan)->num[c];
	free((*p_lan)->num);
	(*p_lan)->len++;
	if (((*p_lan)->num = (int *)malloc(sizeof(int) * ((*p_lan)->len))) == NULL)
		exit(1);
	c = -1;
	while (++c < (int)(*p_lan)->len - 1)
		(*p_lan)->num[c] = temp[c];
	(*p_lan)->num[c] = 0;
	free(temp);
}

t_lan	*sum_lan_nums(t_lan *f, t_lan *s)
{
	int		remainder;
	size_t	c;
	size_t	max;
	t_lan	*res;

// printf("!!!!!!!!\n");
// 	    for (int i = 0; i < f->len; i++)
// 			printf("%d ", f->num[i]);
// 		printf("\n");

// 	printf("!!!!!!!!\n");
// 		for (int i = 0; i < s->len; i++)
// 			printf("%d ", s->num[i]);
// 		printf("\n");

	max = f->len > s->len ? f->len : s->len;
	if ((res = (t_lan *)malloc(sizeof(t_lan))) == NULL)
		exit(1);
	if ((res->num = (int *)malloc(sizeof(int) * max)) == NULL)
		exit(1);
	c = -1;
	while (++c < max)
		res->num[c] = 0;
	res->num[0] = 0;
	res->len = max;
	remainder = 0;
	c = 0;
	while (c < max || remainder > 0)
	{
		if (c == res->len)
			change_lan_rank(&res);
		res->num[c] = (c < f->len ? f->num[c] : 0) + remainder + (c < s->len ? s->num[c] : 0);
		remainder = (res->num[c] > 9999) ? 1 : 0;
		if (remainder == 1)
			res->num[c] -= 10000;
		c++;
	}
	if (f != s)
	{
		free(s->num);
		free(s);
	}
	free(f->num);
	free(f);
	return (res);
}
