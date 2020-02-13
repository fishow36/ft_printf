/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshor <eshor@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 14:30:27 by eshor             #+#    #+#             */
/*   Updated: 2020/02/13 18:54:34 by eshor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*add_plus(char *str, char to_add)
{
	int		len;
	int		i;
	char	*res;

	len = ft_strlen(str);
	if (!(res = (char*)malloc(sizeof(char) * (len + 2))))
		return (NULL);
	res[len + 1] = '\0';
	res[0] = to_add;
	i = 1;
	while (str[i - 1])
	{
		res[i] = str[i - 1];
		i++;
	}
	ft_strdel(&str);
	return (res);
}

char	*add_zero(char *str, char type, int i)
{
	char	*res;

	if (type != 'x' && type != 'X' && type != 'o')
		return (str);
	else
	{
		if (type == 'x' || type == 'X')
		{
			res = (char*)malloc(sizeof(char) * (ft_strlen(str) + 3));
			res[1] = type;
			while (++i < (int)ft_strlen(str))
				res[i + 2] = str[i];
			res[i + 2] = '\0';
		}
		else
		{
			res = (char*)malloc(sizeof(char) * (ft_strlen(str) + 2));
			while (++i < (int)ft_strlen(str))
				res[i + 1] = str[i];
			res[i + 1] = '\0';
		}
		res[0] = '0';
		ft_strdel(&str);
		return (res);
	}
}
