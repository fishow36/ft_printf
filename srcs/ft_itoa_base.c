/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshor <eshor@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 17:07:43 by eshor             #+#    #+#             */
/*   Updated: 2020/02/10 17:32:17 by eshor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_strrev(char **str)
{
	int		i;
	int		len;
	char	temp;

	len = ft_strlen(*str);
	i = 0;
	while (i < len / 2)
	{
		temp = (*str)[i];
		(*str)[i] = (*str)[len - 1 - i];
		(*str)[len - 1 - i] = temp;
		i++;
	}
}

char		get_remnant(unsigned long long value, unsigned long long base)
{
	if (value % base < 10)
		return (value % base + 48);
	else if (value % base == 10)
		return ('a');
	else if (value % base == 11)
		return ('b');
	else if (value % base == 12)
		return ('c');
	else if (value % base == 13)
		return ('d');
	else if (value % base == 14)
		return ('e');
	else
		return ('f');
}

char		*ft_itoa_base(unsigned long long value, unsigned long long base)
{
	char					*str;
	int						i;
	unsigned long long		temp;

	i = 0;
	if (value == 0)
		return (ft_strdup("0\0"));
	temp = value;
	while (temp > 0)
	{
		temp = temp / base;
		i++;
	}
	if (!(str = (char*)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	i = 0;
	while (value > 0)
	{
		str[i] = get_remnant(value, base);
		value = value / base;
		i++;
	}
	str[i] = '\0';
	ft_strrev(&str);
	return (str);
}
