/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshor <eshor@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 18:10:46 by eshor             #+#    #+#             */
/*   Updated: 2020/02/20 23:52:14 by eshor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_int(t_lst *temp, long long int nbr, int *w_p)
{
	char	*str;
	int		len;

	str = create_str(nbr, w_p);
	len = (nbr < 0) ? (int)ft_strlen(str) - 1 : (int)ft_strlen(str);
	if (w_p[1] != -1)
	{
		if (len < w_p[1])
			prec_greater(&str, &temp, w_p);
		add_and_change(&str, nbr, &temp);
	}
	if (w_p[0] > (int)ft_strlen(str))
	{
		if (w_p[1] != -1)
			prec_and_width(&temp, &str, w_p);
		else
			prec_no_width(&str, temp, nbr, w_p);
	}
	else
		add_s_or_p(&str, temp, nbr);
	ft_putstr(str);
	len = (int)ft_strlen(str);
	ft_strdel(&str);
	return (len);
}

int		print_long(t_lst *temp, long nbr, int *w_p)
{
	return (print_int(temp, (long long)nbr, w_p));
}

int		print_long_long(t_lst *temp, long long nbr, int *w_p)
{
	return (print_int(temp, (long long)nbr, w_p));
}

int		print_short(t_lst *temp, int nbr, int *w_p)
{
	short num;

	num = (short)nbr;
	return (print_int(temp, (long long)num, w_p));
}

int		print_sshort(t_lst *temp, int nbr, int *w_p)
{
	char num;

	num = (char)nbr;
	return (print_int(temp, (long long)num, w_p));
}
