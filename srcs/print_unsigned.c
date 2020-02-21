/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshor <eshor@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 21:54:17 by eshor             #+#    #+#             */
/*   Updated: 2020/02/21 21:12:03 by eshor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_uint(t_lst *t, unsigned long long n, int *w_p)
{
	char	*str;
	char	flag[3];
	int		len;

	flag[2] = 0;
	str = create_str_u(n, &t, w_p, &(flag[2]));
	if (t->flags[2] == '-' || (w_p[0] != 0 && w_p[1] != -1))
		t->flags[0] = '?';
	if (w_p[1] > 0)
	{
		prec_u(&str, t, w_p);
		if ((t->flags[4] == '#' && !(str[0] == '0' && t->type == 'o') && !(n ==
		0 && (t->type == 'x' || t->type == 'X'))) || (n == 0 && flag[2] == 'p'))
			str = add_zero(str, t->type, -1);
	}
	if (n == 0 && flag[2] == 'p' && w_p[1] < 0)
		str = add_zero(str, t->type, -1);
	if (w_p[0] != 0)
		width_u(&str, t, w_p, n);
	if (w_p[0] == 0 && w_p[1] < 1 && t->flags[4] == '#' && n != 0)
		str = add_zero(str, t->type, -1);
	ft_putstr(str);
	len = (int)ft_strlen(str);
	ft_strdel(&str);
	return (len);
}

int		print_ulong(t_lst *temp, unsigned long nbr, int *w_p)
{
	return (print_uint(temp, (unsigned long long)nbr, w_p));
}

int		print_ulong_long(t_lst *temp, unsigned long long nbr, int *w_p)
{
	return (print_uint(temp, nbr, w_p));
}

int		print_ushort(t_lst *temp, unsigned int nbr, int *w_p)
{
	unsigned short num;

	num = (unsigned short)nbr;
	return (print_uint(temp, (unsigned long long)num, w_p));
}

int		print_usshort(t_lst *temp, int nbr, int *w_p)
{
	unsigned char num;

	num = (unsigned char)nbr;
	return (print_uint(temp, (long long)num, w_p));
}
