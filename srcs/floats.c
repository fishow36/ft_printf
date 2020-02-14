/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floats.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrogg <mbrogg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 10:08:36 by mbrogg            #+#    #+#             */
/*   Updated: 2020/02/14 22:18:06 by mbrogg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char    *ft_dtoa_two(t_ulli value, int shift)
{
	char        *str;
	unsigned	i;
	int         flag;

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

t_ulli  ft_power(unsigned num)
{
    t_ulli      res_llu;

    res_llu = 1;
    while (num-- > 0)
    {
        res_llu *= 2;
    }
    return (res_llu);
}

char    *str_from_db(t_lan i_db, t_lanch f_db, int prec)
{
    char    *res;
    int     amount;
    int     c;
    int     i;
    int     j;
    int     len;

    i = -1;
    c = 0;
    j = i_db.len - 1;
    len = i_db.len * 4 + prec + 1 + 1;
    res = (char *)malloc(sizeof(char) * (len));
    while (j >= 0)
    {
        i = -1;
        if (i_db.num[j] == 0)
            while (++i < 4)
                res[c++] = 0 + '0'; 
        else
        {
            ft_strcpy(res + c, ft_itoa(i_db.num[i_db.len -  c / 4 - 1], &amount));
            c += amount;
        }
        j--;
    }
    res[c++] = '.';
    j = f_db.len - 1;
    i = 0;
    while (j > -1 && ++i <= prec)
        res[c++] = f_db.num[j--] + '0';
    while (++i <= prec)
        res[c++] = '0';
    res[c] = '\0';
    return (res);
}

char    *parse_str_to_lan(char *i_part, char *f_part, int prec)
{
    t_lan   i_db;
    t_lanch f_db;
    char    *output;

    i_db = create_lan_from_bitstr(i_part, 1);
    f_db = create_lanch_from_bitstr(f_part);
    output = str_from_db(i_db, f_db, prec);
    return (output);
}

char    *ldbl_to_str(t_ldbl *input, int shift, int prec)
{
    char    *i_part;
    char    *f_part;
	char	*temp;

	f_part = NULL;
    if ((i_part = ft_dtoa_two(input->parts.mant, shift)) == NULL)
		return (NULL);
	if (shift > 0)
	{
		if (!(f_part = ft_strncpy(f_part, i_part + shift + 1, 64 - shift - 1)))
			return (NULL);
		temp = i_part;
		if ((i_part = ft_strncpy(i_part, i_part, shift + 1)) == NULL)
			return (NULL);
		free(temp);
	}
    return (parse_str_to_lan(i_part, f_part, prec));
}

char    *lfloat(long double input, int prec)
{
    t_ldbl		res;
    char        *output;
	unsigned	mid_exp;
    int         c;
    
    c = 0;
	mid_exp = 0;
	mid_exp = mid_exp | ((1 << 15) >> 1) - 1;
    res.origin = input;
	output = ldbl_to_str(&res, res.parts.exp - mid_exp, prec);
    while (output[c] != '\0' && output[c] != '.')
        c++;
    while (prec-- >= 0 && output[c] != '\0')
        c++;
    output[c] = '\0';
    return (output);
}

void    print_lfloat(t_lst *temp, long double input, int prec)
{
    printf("%s\n", lfloat(input, prec));
}