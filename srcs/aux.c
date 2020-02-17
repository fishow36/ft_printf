/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshor <eshor@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 17:43:05 by eshor             #+#    #+#             */
/*   Updated: 2020/02/17 12:56:00 by eshor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		is_valid(char c, char n, char type)
{
	if (type == 'f' && (c == '0' || c == '+'
	|| c == '-' || c == ' ' || c == '#'))
		return (1);
	else if (type == 'l' && (c == 'h' || c == 'l' || c == 'L'
	|| (c == 'h' && n == 'h') || (c == 'l' && n == 'l')))
		return (1);
	else
		return (0);
}

int		type_pos(const char *format, int pos)
{
	while (is_valid(format[pos], format[pos + 1], 'f') == 1)
		pos++;
	if (format[pos] == '*')
		pos++;
	else
		while (format[pos] >= '0' && format[pos] <= '9')
			pos++;
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
	if (is_valid(format[pos], format[pos + 1], 'l'))
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

char	*find_w_or_p(const char *format, int len, int temp)
{
	char *res;

	if (!(res = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	len = 0;
	while (format[temp] > 47 && format[temp] < 58)
	{
		res[len] = format[temp];
		len++;
		temp++;
	}
	res[len] = '\0';
	return (res);
}

char	*fill_number(const char *format, int *pos, int *len, char w_or_p)
{
	char	*str;
	int		temp;

	temp = *pos;
	while (format[*pos] > 47 && format[*pos] < 58)
	{
		(*pos)++;
		(*len)++;
	}
	if (len == 0)
	{
		if (w_or_p == 'w')
			return (NULL);
		else
		{
			if (!(str = ft_strdup("0")))
				return (NULL);
			else
				return (str);
		}
	}
	else if (!(str = find_w_or_p(format, *len, temp)))
		return (NULL);
	else
		return (str);
}
