/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_aux2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshor <eshor@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 13:04:19 by eshor             #+#    #+#             */
/*   Updated: 2020/02/20 23:53:00 by eshor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*create_str(long long int nbr, int *w_p)
{
	char *str;

	if (nbr == 0 && w_p[1] == 0)
		str = ft_strdup("");
	else
		str = ft_itoa_long(nbr);
	return (str);
}

void	add_and_change(char **str, long long int nbr, t_lst **temp)
{
	if ((*temp)->flags[1] == '+' && nbr >= 0)
	{
		*str = add_plus(*str, '+');
		(*temp)->flags[1] = '?';
		(*temp)->flags[3] = '?';
	}
	else if ((*temp)->flags[3] == ' ' && nbr >= 0)
	{
		*str = add_plus(*str, ' ');
		(*temp)->flags[3] = '?';
	}
}

void	prec_and_width(t_lst **temp, char **str, int *w_p)
{
	(*temp)->flags[0] = '?';
	(*temp)->flags[1] = '?';
	(*temp)->flags[3] = '?';
	*str = int_width(*str, w_p[0], *temp);
}
