/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floats.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kprmk <kprmk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 10:08:36 by mbrogg            #+#    #+#             */
/*   Updated: 2020/02/20 01:18:56 by kprmk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*only_frac_input(char *frac, int *sh_pr_sg)
{
	t_lanch	f_db;
	char	*res;
	int		c;
	int		len;
	int		flag;

	c = 0;
	len = sh_pr_sg[1] + sh_pr_sg[2] + 2;
	flag = create_lanch_from_bitstr(&f_db, frac, sh_pr_sg[1]);
	if ((res = (char *)malloc(sizeof(char) * (len + 1))) == NULL)
		return (NULL);
	if (sh_pr_sg[2] == 1)
		res[c++] = '-';
	res[c++] = (flag == 0) ? '0' : '1';
	if (sh_pr_sg[1] != 0)
		res[c++] = '.';
	while (sh_pr_sg[1]-- > 0)
		res[c++] = f_db.num[--f_db.len] + '0';
	res[c] = '\0';
	return (res);
}

char	*parse_str_to_lan(char *i_part, char *f_part, int *sh_pr_sg)
{
	t_lan	i_db;
	t_lanch	f_db;
	int		flag;

	i_db = create_lan_from_bitstr(i_part);
	if ((flag = create_lanch_from_bitstr(&f_db, f_part, sh_pr_sg[1])) == 1)
		i_db = sum_lan_nums(i_db, power_of_two_lan(0));
	return (str_from_db(i_db, f_db, sh_pr_sg[1], sh_pr_sg[2]));
}

char	*ldbl_to_str(t_ldbl *input, int shift, int prec)
{
	char	*i_part;
	char	*f_part;
	char	*temp;
	int		ar[3];

	ar[0] = shift;
	ar[1] = prec;
	ar[2] = input->parts.sign;
	f_part = NULL;
	if ((i_part = ft_dtoa_two(input->parts.mant, shift)) == NULL)
		return (NULL);
	if (shift >= 0)
	{
		if (!(f_part = ft_strncpy(f_part, i_part + shift + 1, 64 - shift - 1)))
			return (NULL);
		temp = i_part;
		if ((i_part = ft_strncpy(i_part, i_part, shift + 1)) == NULL)
			return (NULL);
		free(temp);
		return (parse_str_to_lan(i_part, f_part, ar));
	}
	else
		return (only_frac_input(i_part, ar));
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

char	*lfloat(long double input, int prec)
{
	t_ldbl		res;
	char		*output;
	unsigned	mid_exp;
	int			c;

	c = 0;
	mid_exp = 0;
	mid_exp = (mid_exp | ((1 << 15) >> 1)) - 1;
	if (prec == -1)
		prec = 6;
	res.origin = input;
	if ((output = ldbl_to_str(&res, res.parts.exp - mid_exp, prec)) == NULL)
		return (NULL);
	while (output[c] != '\0' && output[c] != '.')
		c++;
	while (prec-- >= 0 && output[c] != '\0')
		c++;
	output[c] = '\0';
	return (output);
}