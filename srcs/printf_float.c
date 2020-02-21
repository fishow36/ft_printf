/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_float.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshor <eshor@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 12:57:42 by eshor             #+#    #+#             */
/*   Updated: 2020/02/21 22:58:03 by eshor            ###   ########.fr       */
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
	if (w_p[0] > 0)
		*str = int_width(*str, w_p[0], temp);
}

char	*add_dot(char *str)
{
	char	*res;
	int		len;
	int		i;

	len = (int)ft_strlen(str);
	res = (char*)malloc(sizeof(char) * (len + 2));
	if (!res)
		return (NULL);
	i = 0;
	while (i < len)
	{
		res[i] = str[i];
		i++;
	}
	res[i] = '.';
	res[i + 1] = '\0';
	ft_strdel(&str);
	return (res);
}

char	*float_zeroflag(char *str, long double input, t_lst *temp, int w)
{
	char	*res;

	if (!(res = int_width(str, w, temp)))
		return (NULL);
	if (input < 0)
		res[0] = '-';
	else if (temp->flags[1] == '+' && input >= 0)
		res[0] = '+';
	else if (temp->flags[3] == ' ')
		res[0] = ' ';
	return (res);
}

int		print_lfloat(t_lst *temp, long double input, int *w_p)
{
	char	*str;
	int		len;

	if ((str = lfloat(input, w_p[1])) == NULL)
		return (0);
	if (ft_strlen(str) > 2 && !(str[1] >= '0' && str[1] <= '9') && str[1] != '.')
		return (print_inf_nan(&str, w_p[0], temp));
	if (temp->flags[4] == '#' && w_p[1] == 0)
		str = add_dot(str);
	if (w_p[0] > (int)ft_strlen(str))
	{
		if (temp->flags[2] == '-' || (temp->flags[2] != '-'
		&& temp->flags[0] != '0'))
			add_sorp_fl(temp, &str, w_p);
		else if (temp->flags[0] == '0')
			str = float_zeroflag(str, input, temp, w_p[0]);
	}
	else
		add_sorp_fl(temp, &str, w_p);
	ft_putstr(str);
	len = (int)ft_strlen(str);
	ft_strdel(&str);
	return (len);
}
