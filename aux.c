/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshor <eshor@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 17:43:05 by eshor             #+#    #+#             */
/*   Updated: 2020/02/06 14:04:00 by eshor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int type_pos(const char *format, int pos)
{
	while ((format[pos] == '0' || format[pos] == '+'
	|| format[pos] == '-' || format[pos] == ' '
	|| format[pos] == '#') && format[pos])
		pos++;
	if (format[pos] == '*')
		pos++;
	else
	{
		while (format[pos] >= '0' && format[pos] <= '9')
			pos++;
	}
	if (format[pos] == '.')
	{
		pos++;
		if (format[pos] == '*')
			pos++;
		else
		{
			while (format[pos] >= '0' && format[pos] <= '9')
				pos++;
		}
	}
	if ((format[pos] == 'h') || (format[pos] == 'l') || format[pos] == 'L'
	|| (format[pos] == 'h' && format[pos + 1] == 'h') || (format[pos] == 'l' && format[pos + 1] == 'l'))
	{
		while (format[pos] == 'h' || format[pos] == 'l' || format[pos] == 'L')
			pos++;
	}
	return (pos);
}

void	change_case(char **str)
{
	int i;

	i = 0;
	while ((*str)[i])
	{
		if ((*str)[i] >= 'a' && (*str)[i] <= 'f')
			(*str)[i] -= 32;
		i++;
	}
}
