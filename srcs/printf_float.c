/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_float.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshor <eshor@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 12:57:42 by eshor             #+#    #+#             */
/*   Updated: 2020/02/17 14:26:02 by eshor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_float(t_lst *temp, double input, int *w_p)
{
	return (print_lfloat(temp, (long double)input, w_p));
}

void	add_sorp_fl(t_lst *temp, char **str, int *w_p)
{
	if (temp->flags[1] == '+' && (*str)[0] != '-')
		*str = add_plus(*str, '+');
	else if (temp->flags[3] == ' ' && (*str)[0] != '-')
		*str = add_plus(*str, ' ');
	*str = int_width(*str, w_p[0], temp);
}

int		print_lfloat(t_lst *temp, long double input, int *w_p)
{
	char	*str;
	int		len;

	str = lfloat(input, w_p[1]);
	if (w_p[0] > (int)ft_strlen(str))
	{
		if (temp->flags[2] == '-' || (temp->flags[2] != '-'
		&& temp->flags[0] != '0'))
			add_sorp_fl(temp, &str, w_p);
		else if (temp->flags[0] == '0')
		{
			str = int_width(str, w_p[0], temp);
			if (input < 0)
				str[0] = '-';
			else if (temp->flags[1] == '+' && input >= 0)
				str[0] = '+';
			else if (temp->flags[3] == ' ')
				str[0] = ' ';
		}
	}
	ft_putstr(str);
	len = (int)ft_strlen(str);
	ft_strdel(&str);
	return (len);
}
