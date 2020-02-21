/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrogg <mbrogg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 19:44:40 by mbrogg            #+#    #+#             */
/*   Updated: 2020/02/21 19:22:08 by mbrogg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	unsigned	razr(int *n, int *flag, int *i)
{
	unsigned	cp;
	unsigned	num;

	num = *n < 0 ? (unsigned)(-*n) : *n;
	*flag = *n < 0 ? 1 : 0;
	cp = num;
	if (cp == 0)
		(*i)++;
	else
	{
		while (cp)
		{
			(*i)++;
			cp /= 10;
		}
	}
	*i = *flag ? (*i + 1) : *i;
	return (num);
}

static	int			ft_pow(int i)
{
	int	res;

	res = 1;
	while (i--)
		res *= 10;
	return (res);
}

char				*ft_itoa(int n, int *amount)
{
	char		*res;
	int			i;
	int			sign;
	unsigned	num;

	i = 0;
	num = razr(&n, &sign, &i);
	res = (char *)malloc(sizeof(char) * (i + 1));
	if (!res)
		return (NULL);
	if (sign)
		res[0] = '-';
	while (sign++ != i)
	{
		res[sign - 1] = (num / ft_pow(i - sign)) + '0';
		num %= ft_pow(i - sign);
	}
	res[--sign] = '\0';
	*amount = ft_strlen(res);
	return (res);
}
