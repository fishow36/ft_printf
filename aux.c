/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshor <eshor@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 17:43:05 by eshor             #+#    #+#             */
/*   Updated: 2020/02/02 17:43:20 by eshor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		is_even(const char *format, int i)
{
	int amount;

	amount = 0;
	i--;
	while (format[i] && format[i] == '%')
	{
		if (format[i] == '%')
			amount++;
		i--;
	}
	if (amount % 2 == 0)
		return (1);
	else
		return (0);
}

void	change_case(char **str)
{
	int i;

	i = 0;
	while ((*str)[i])
	{
		if ((*str)[i] >= 'A' && (*str)[i] <= 'F')
			(*str)[i] += 32;
		i++;
	}
}
