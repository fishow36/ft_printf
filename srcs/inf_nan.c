/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inf_nan.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshor <eshor@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 21:55:30 by eshor             #+#    #+#             */
/*   Updated: 2020/02/21 22:34:30 by eshor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_inf_nan(char **str, int w, t_lst *temp)
{
	int len;

	temp->flags[0] = '?';
	if ((*str)[0] == 'i')
	{
		if (temp->flags[1] == '+')
			*str = add_plus(*str, '+');
		else if (temp->flags[3] == ' ')
			*str = add_plus(*str, ' ');
	}
	if (w > (int)ft_strlen(*str))
		*str = int_width(*str, w, temp);
	len = (int)ft_strlen(*str);
	ft_putstr(*str);
	ft_strdel(str);
	return (len);
}
