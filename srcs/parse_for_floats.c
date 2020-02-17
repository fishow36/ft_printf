/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_for_floats.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kprmk <kprmk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 23:02:56 by mbrogg            #+#    #+#             */
/*   Updated: 2020/02/17 16:01:57 by kprmk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_dtoa_two(t_ulli value, int shift)
{
	char		*str;
	unsigned	i;
	int			flag;

	i = 0;
	flag = shift < 0 ? -shift : 0;
	if (value == 0)
		return (ft_strdup("0"));
	if (!(str = (char*)malloc(sizeof(char) * (64 + flag + 1))))
		return (NULL);
	while (value > 0 || i < 64)
	{
		str[i++] = value % 2 + '0';
		value = value / 2;
	}
	while (--flag > 0)
		str[i++] = '0';
	str[i] = '\0';
	ft_strrev(&str);
	return (str);
}

char	*str_from_db_after_loop(t_lanch f_db, char *res, int *ar)
{
	res[(ar[2])++] = '.';
	ar[1] = f_db.len - 1;
	ar[0] = 0;
	while (ar[1] > -1 && ++(ar[0]) <= ar[5])
		res[(ar[2])++] = f_db.num[(ar[1])--] + '0';
	while (++(ar[0]) <= ar[5])
		res[(ar[2])++] = '0';
	res[ar[2]] = '\0';
	return (res);
}

/*
**	arr - > 0 - i, 1 - j, 2 - c, 3 - len, 4 - amount, 5 - prec
*/

char	*str_from_db(t_lan i_db, t_lanch f_db, int prec, int sign)
{
	char	*res;
	int		ar[6];

	ar[0] = -1;
	ar[1] = i_db.len - 1;
	ar[2] = 0;
	ar[3] = 0;
	ar[5] = prec;
	res = (char *)malloc(sizeof(char) * (i_db.len * 4 + sign + prec + 2));
	if (sign == 1)
		res[(ar[2])++] = '-';
	while (ar[1] >= 0)
	{
		ar[0] = -1;
		if (i_db.num[ar[1]] == 0)
			while (++(ar[0]) < 4)
				res[(ar[2])++] = 0 + '0';
		else
		{
			ft_strcpy(res + ar[2], ft_itoa(i_db.num[ar[1]],
				&ar[4]));
			ar[2] += ar[4];
			res[ar[2]] = '\0';
		}
		(ar[1])--;
	}
	return (str_from_db_after_loop(f_db, res, ar));
}
