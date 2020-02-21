/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floats.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrogg <mbrogg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 10:08:36 by mbrogg            #+#    #+#             */
/*   Updated: 2020/02/22 01:52:37 by mbrogg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*only_frac_input(char *frac, int *sh_pr_sg)
{
	t_lanch	*f_db;
	char	*res;
	int		c;
	int		len;
	int		f;

	c = 0;
	len = sh_pr_sg[1] + sh_pr_sg[2] + 2;
	f = create_lanch_from_bitstr(&f_db, frac, sh_pr_sg[1]);
	if ((res = (char *)malloc(sizeof(char) * (len + 1))) == NULL)
		return (NULL);
	if (sh_pr_sg[2] == 1)
		res[c++] = '-';
	res[c++] = (f == 0) ? '0' : '1';
	if (sh_pr_sg[1] != 0)
		res[c++] = '.';
	f = ft_str_is_null_value(frac);
	while (sh_pr_sg[1]-- > 0)
		res[c++] = (--f_db->len > -1 && f == 1) ?
		f_db->num[f_db->len] + '0' : '0';
	res[c] = '\0';
	free(f_db->num);
	free(f_db);
	free(frac);
	return (res);
}

char	*parse_str_to_lan(char *i_part, char *f_part, int *sh_pr_sg)
{
	t_lan	*i_db;
	t_lanch	*f_db;
	int		flag;
	int		c;

	c = -1;
	i_db = create_lan_from_bitstr(i_part);
	free(i_part);
	if (ft_str_is_null_value(f_part) == 0)
		f_db = NULL;
	else if ((flag = create_lanch_from_bitstr(&f_db, f_part, sh_pr_sg[1])))
	{
		if (flag == 2 || (flag == 1 && i_db->num[0] % 2 == 1))
			i_db = sum_lan_nums(i_db, power_of_two_lan(0));
	}
	free(f_part);
	return (str_from_db(i_db, f_db, sh_pr_sg[1], sh_pr_sg[2]));
}

char	*lbdl_to_str_inside(int *ar, char *i_pt, char *f_pt)
{
	char	*temp;

	if (ar[0] >= 0)
	{
		if (ar[0] > 64)
		{
			if ((f_pt = ft_strncpy(f_pt, "0", 1)) == NULL)
				exit(1);
		}
		else
		{
			if (!(f_pt = ft_strncpy(f_pt, i_pt + ar[0] + 1, 64 - ar[0] - 1)))
				exit(1);
			temp = i_pt;
			if ((i_pt = ft_strncpy(i_pt, i_pt, ar[0] + 1)) == NULL)
				exit(1);
			free(temp);
		}
		return (parse_str_to_lan(i_pt, f_pt, ar));
	}
	else
		return (only_frac_input(i_pt, ar));
}

/*
**	l_i -> length integer_part
*/

char	*ldbl_to_str(t_ldbl *input, int shift, int prec)
{
	char	*i_pt;
	char	*f_pt;
	int		l_i;
	int		ar[3];

	ar[0] = shift;
	ar[1] = prec;
	ar[2] = input->parts.sign;
	l_i = 0;
	if (shift > 63)
		l_i = shift - 63;
	f_pt = NULL;
	if ((ar[0] = check_inf_nan(input)) == -1)
		return (ft_strdup("-inf"));
	else if (ar[0] == 1)
		return (ft_strdup("inf"));
	else if (ar[0] == 2)
		return (ft_strdup("nan"));
	else
	{
		ar[0] = shift;
		if ((i_pt = ft_dtoa_two(input->parts.mant, ar[0], &l_i)) == NULL)
			exit(1);
		return (lbdl_to_str_inside(ar, i_pt, f_pt));
	}
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
	if (!(output = ldbl_to_str(&res, res.parts.exp - mid_exp, prec)))
		exit(1);
	while (output[c] != '\0' && output[c] != '.')
		c++;
	while (prec-- >= 0 && output[c] != '\0')
		c++;
	output[c] = '\0';
	return (output);
}
