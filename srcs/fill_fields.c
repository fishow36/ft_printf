/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_fields.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshor <eshor@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 17:45:13 by eshor             #+#    #+#             */
/*   Updated: 2020/02/13 18:35:30 by eshor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		find_flags(const char *format, int pos, t_lst **node)
{
	while ((format[pos] == '0' || format[pos] == '+'
	|| format[pos] == '-' || format[pos] == ' '
	|| format[pos] == '#') && format[pos])
	{
		if (format[pos] == '0')
			(*node)->flags[0] = '0';
		else if (format[pos] == '+')
			(*node)->flags[1] = '+';
		else if (format[pos] == '-')
			(*node)->flags[2] = '-';
		else if (format[pos] == ' ')
			(*node)->flags[3] = ' ';
		else if (format[pos] == '#')
			(*node)->flags[4] = '#';
		pos++;
	}
	return (pos);
}

int		find_width(const char *format, int pos, t_lst **node)
{
	int		len;

	len = 0;
	if (format[pos] == '*')
	{
		pos++;
		if (!((*node)->width = ft_strdup("*")))
			return (-1);
		if (format[pos] >= '0' && format[pos] <= '9')
		{
			(*node)->stars++;
			ft_strdel(&((*node)->width));
			(*node)->width = fill_number(format, &pos, &len, 'w');
		}
	}
	else
		(*node)->width = fill_number(format, &pos, &len, 'w');
	return (pos);
}

int		find_prec(const char *format, int pos, t_lst **node)
{
	int		len;

	len = 0;
	if (format[pos] == '.')
	{
		pos++;
		if (format[pos] == '*')
		{
			pos++;
			if (!((*node)->precision = ft_strdup("*")))
				return (-1);
		}
		else
			(*node)->precision = fill_number(format, &pos, &len, 'p');
	}
	return (pos);
}

int		find_length(const char *format, int pos, t_lst **node)
{
	if (format[pos] == 'L')
		(*node)->length[0] = 'L';
	else if (format[pos] == 'h' && format[pos + 1] == 'h')
	{
		(*node)->length[0] = 'h';
		(*node)->length[1] = 'h';
	}
	else if (format[pos] == 'l' && format[pos + 1] == 'l')
	{
		(*node)->length[0] = 'l';
		(*node)->length[1] = 'l';
	}
	else if (format[pos] == 'h')
		(*node)->length[0] = 'h';
	else if (format[pos] == 'l')
		(*node)->length[0] = 'l';
	if ((format[pos] == 'h' && format[pos + 1] == 'h')
	|| (format[pos] == 'l' && format[pos + 1] == 'l'))
		return (pos + 2);
	else if (format[pos] == 'h' || format[pos] == 'l'
	|| format[pos] == 'L')
		return (pos + 1);
	else
		return (pos);
}

int		find_type(const char *format, int pos, t_lst **node)
{
	(*node)->type = format[pos];
	return (pos + 1);
}
