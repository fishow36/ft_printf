/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floats.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrogg <mbrogg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 10:08:36 by mbrogg            #+#    #+#             */
/*   Updated: 2020/02/14 20:07:16 by mbrogg           ###   ########.fr       */
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

char    *print_ldbl_dec(char *i_part, char *f_part)
{
    int         power;
    unsigned    len;
    t_ulli      i_res;
    long double f_res;

    power = ft_strlen(i_part);
    len = power;
    i_res = 0;
    f_res = 0.0;
    if (f_part == NULL)
	    printf("%s\n", i_part);
    else
    {
        while (--power >= 0)
        {
            if (i_part[power] == '1')
                i_res += ft_power(len - power - 1);
        }
        len = ft_strlen(f_part);
        power = 0;
        while (power < len)
        {
            if (f_part[power] == '1')
                f_res += 1. / ft_power(power + 1);
            power++;
        }
        printf("%llu\n", i_res);    
        printf("%Lf\n", f_res);
    }
}

char    *str_from_db(t_lan i_db, t_lanch f_db)
{
    char    *res;
    int     c;
    int     i;
    int     len;

    i = -1;
    c = i_db.len;
    len = i_db.len * 4 + f_db.len + 1;
    res = (char *)malloc(sizeof(char) * (len));
    while (c < len)
    {
        i = -1;
        if (ft_itoa(i_db.num[c] == 0))
            while (++i < 4)
                res[c++] = 0; 
        else
        {
            res[c] = i_db.num[c] / 1000 % 1000;
            res[c + 1] = i_db.num[c] / 100 % 100;
            res[c + 2] = i_db.num[c] / 10 % 10;
            res[c + 3] = i_db.num[c] % 10;
            c += 4;
        }
    }
    c = f_db.len - 1;
    while (c > -1)
        res[c] = f_db.num[c--];
    printf("-> %s\n", res);
    return (res);
}

void    parse_str_to_lan(char *i_part, char *f_part)
{
    t_lan   i_db;
    t_lanch f_db;
    char    *output;

    i_db = create_lan_from_bitstr(i_part, 1);
    f_db = create_lanch_from_bitstr(f_part);
    printf("\n");
    print_lan(i_db);
    print_lanch(f_db);
    output = str_from_db(i_db, f_db);
}

int     ldbl_to_str(t_ldbl *input, int shift)
{
    char    *i_part;
    char    *f_part;
	char	*temp;

	f_part = NULL;
    if ((i_part = ft_dtoa_two(input->parts.mant, shift)) == NULL)
		return (-1);
	if (shift > 0)
	{
		if (!(f_part = ft_strncpy(f_part, i_part + shift + 1, 64 - shift - 1)))
			return (-1);
		temp = i_part;
		if ((i_part = ft_strncpy(i_part, i_part, shift + 1)) == NULL)
			return (-1);
		free(temp);
	}
    printf("%s ", i_part);
    printf("%s\n", f_part);
    parse_str_to_lan(i_part, f_part);
}

char    *lfloat(long double input)
{
    char        *output;
    t_ldbl		res;
    unsigned	shift;
	unsigned	mid_exp;
	size_t		sign;
    t_lan       mant_lan;

	mid_exp = 0;
    output = NULL;
	mid_exp = mid_exp | ((1 << 15) >> 1) - 1;
    res.origin = input;
	ldbl_to_str(&res, res.parts.exp - mid_exp);
    return (output);
}

void    print_lfloat(t_lst *temp, long double input)
{
    lfloat(input);
}