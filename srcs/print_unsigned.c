/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshor <eshor@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 18:10:49 by eshor             #+#    #+#             */
/*   Updated: 2020/02/11 18:25:29 by eshor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int    print_uint(t_lst *temp, unsigned long long nbr, int *w_p)
{
    char    *str;
    char    flag[2];
    int len;

    if (nbr == 0 && w_p[1] == 0 && !(temp->type == 'o' && temp->flags[4] == '#'))
        str = ft_strdup("");
    else if (temp->length[0] != 'l' && nbr > 4294967295 && temp->type != 'p')
        str = ft_strdup("0");
    else if (temp->type == 'u')
        str = ft_itoa_base(nbr, 10);
    else if (temp->type == 'o')
        str = ft_itoa_base(nbr, 8);
    else
    {
        str = ft_itoa_base(nbr, 16);
        if (temp->type == 'X')
            change_case(&str);
        else if (temp->type == 'p')
            temp->type = 'x';
    }
    if (temp->flags[2] == '-' || (w_p[0] != 0 && w_p[1] != -1))
        temp->flags[0] = '?';
    if (w_p[1] != -1)
	{
		if ((int)ft_strlen(str) < w_p[1])
		{
			flag[0] = temp->flags[0];
			flag[1] = temp->flags[2];
			temp->flags[2] = '?';
			temp->flags[0] = '0';
			str = int_width(str, w_p[1], temp);
			temp->flags[0] = flag[0];
			temp->flags[2] = flag[1];
		}
        if (temp->flags[4] == '#' && nbr != 0)
            str = add_zero(str, temp->type, w_p[1]);
	}
    if (w_p[0] != 0)
    {
        if (w_p[1] != -1)
        {
            str = int_width(str, w_p[0], temp);
        }
        else
        {
            if (temp->flags[0] == '0')
            {
                if (temp->flags[4] == '#')
                {
                    if (temp->type == 'x' || temp->type == 'X')
                        w_p[0] = w_p[0] - 2;
                    else if (temp->type == 'o')
                        w_p[0]--;
                }
                str = int_width(str, w_p[0], temp);
            }
            if (temp->flags[4] == '#')
            {
                str = add_zero(str, temp->type, w_p[1]);
                str = int_width(str, w_p[0], temp);
            }
            else
            {
                str = int_width(str, w_p[0], temp);
            }
        }
    }
    if (w_p[0] == 0 && w_p[1] == -1 && temp->flags[4] == '#' && nbr != 0)
        str = add_zero(str, temp->type, w_p[1]);
    ft_putstr(str);
    len = (int)ft_strlen(str);
    ft_strdel(&str);
    return (len);
}

int	print_ulong(t_lst *temp, unsigned long nbr, int *w_p)
{
	return (print_uint(temp, (unsigned long long)nbr, w_p));
}

int	print_ulong_long(t_lst *temp, unsigned long long nbr, int *w_p)
{
	return (print_uint(temp, nbr, w_p));
}

int	print_ushort(t_lst *temp, unsigned int nbr, int *w_p)
{
	return (print_uint(temp, (unsigned long long)nbr, w_p));
}
